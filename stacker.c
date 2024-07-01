void
attachabove(Client *c, Client *target)
{
	Client **tp;
	Client *last;

	if (target) {
		last = lastclient(c);
		last->next = target;
		tp = clientptr(target);
		*tp = c;
		return;
	}

	attach(c);
}

Client **
clientptr(Client *c)
{
	Client **tc;
	for (tc = &c->mon->clients; *tc && *tc != c; tc = &(*tc)->next);
	return tc;
}

int
ismasterclient(Client *client)
{
	Monitor *m = client->mon;
	Client *c;
	int i;

	for (i = 0, c = nexttiled(m->clients); c && i < m->nmaster; c = nexttiled(c->next), ++i)
		if (c == client)
			return 1;

	return 0;
}

Client *
lastclient(Client *c)
{
	Client *last;
	for (last = c; last && last->next; last = last->next);

	return last;
}

Client *
lasttiled(Client *c)
{
	Client *last = NULL;
	for (; c; c = c->next)
		if (ISVISIBLE(c) && ISTILED(c))
			last = c;

	return last;
}

Client *
nthmaster(Client *c, int n, int reduce)
{
	if (!c)
		return NULL;

	return nthtiled(c, MIN(n, c->mon->nmaster), 1);
}

Client *
nthstack(Client *c, int n, int reduce)
{
	if (!c)
		return NULL;

	return nthtiled(c, n + c->mon->nmaster, 1);
}

Client *
nthtiled(Client *c, int n, int reduce)
{
	Client *prev = NULL;
	int i;
	for (i = 1, c = nexttiled(c); c && (i++ < n); prev = c, c = nexttiled(c->next));

	if (!c && reduce) {
		c = prev;
	}

	return c;
}

Client *
inctiled(Client *c, int n)
{
	Client *f;

	if (!c)
		return NULL;

	if (n > 0) {
		f = nexttiled(c->next);
		if (!f) {
			f = nexttiled(c->mon->clients);
		}
	} else {
		f = prevtiled(c);
		if (!f) {
			f = lasttiled(c->mon->clients);
		}
	}
	return f;
}

Client *
prevtiled(Client *c)
{
	Client *p, *r;
	for (p = nexttiled(c->mon->clients), r = NULL; p && p != c && (r = p); p = nexttiled(p->next));
	return r;
}

Client *
prevsel(void)
{
	Monitor *m = selmon;
	Client *c;

	if (!m->clients)
		return NULL;

	for (c = m->stack; c && (!ISVISIBLE(c) || c == m->sel); c = c->snext);
	return c;
}

void
swap(Client *a, Client *b)
{
	Client **ap = clientptr(a);
	Client **bp = clientptr(b);
	Client *an = a->next;
	Client *bn = b->next;

	if (bn == a) {
		b->next = an;
		a->next = b;
		*bp = a;
	} else if (an == b) {
		b->next = a;
		a->next = bn;
		*ap = b;
	} else {
		b->next = an;
		a->next = bn;
		*ap = b;
		*bp = a;
	}
}


void
stackfocus(const Arg *arg)
{
	Monitor *m = selmon;
	Client *c = NULL;

	if (ISINC(arg)) {
		focusstack(&((Arg) { .i = GETINC(arg) }));
		return;
	}

	if (!m->clients)
		return;

	c = stackposclient(arg);

	if (!c)
		return;

	if (c == m->sel) {
		if (arg->i != PREVSEL) {
			stackfocus(&((Arg) { .i = PREVSEL }));
		}
		return;
	}

	focus(c);
	arrange(m);
}

void
stackpush(const Arg *arg)
{
	Monitor *m = selmon;
	Client *c = NULL, *sel = m->sel;

	if (!m->clients)
		return;

	if (ISINC(arg)) {
		stackswap(arg);
		return;
	}

	c = stackposclient(arg);

	if (!c)
		return;

	if (c == sel)
		return;

	detach(sel);
	attachabove(sel, c);

	arrange(m);
}

void
stackswap(const Arg *arg)
{
	Monitor *m = selmon;
	Client *c = NULL, *sel = m->sel;

	if (!m->clients)
		return;

	c = stackposclient(arg);

	if (!c)
		return;

	if (c == sel)
		return;

	swap(sel, c);

	if (!ISINC(arg) && ismasterclient(c)) {
		focus(c);
		sel = c;
	}

	arrange(m);
}

Client *
stackposclient(const Arg *arg)
{
	Monitor *m = selmon;

	if (!m->clients)
		return NULL;

	if (ISINC(arg))
		return inctiled(m->sel, GETINC(arg));

	if (ISMASTER(arg))
		return nthmaster(m->clients, GETMASTER(arg), 1);

	if (ISSTACK(arg))
		return nthstack(m->clients, GETSTACK(arg), 1);

	if (ISLAST(arg))
		return lasttiled(m->clients);

	if (ISPREVSEL(arg))
		return prevsel();

	return nthtiled(m->clients, arg->i, 1);
}
