#define INC(X)                  ((X) + 2000)
#define MASTER(X)               ((X) + 4000)
#define STACK(X)                ((X) + 5000)
#define PREVSEL                 3000
#define LASTTILED               -1
#define ISINC(X)                ((X)->i > 1000 && (X)->i < 3000)
#define ISPREVSEL(X)            ((X)->i == 3000)
#define ISLAST(X)               ((X)->i < 0)
#define GETINC(X)               ((X)->i - 2000)
#define GETMASTER(X)            ((X)->i - 4000)
#define GETSTACK(X)             ((X)->i - 5000)
#define ISMASTER(X)             ((X)->i >= 4000 && (X)->i < 5000)
#define ISSTACK(X)              ((X)->i >= 5000 && (X)->i < 6000)
#define MOD(N,M)                ((N)%(M) < 0 ? (N)%(M) + (M) : (N)%(M))
#define TRUNC(X,A,B)            (MAX((A), MIN((X), (B))))
#define ISTILED(C)              (C && C->win && !(C->isfloating))

static void attachabove(Client *c, Client *target);
static Client **clientptr(Client *c);
static int ismasterclient(Client *c);
static Client *lastclient(Client *c);
static Client *lasttiled(Client *c);
static Client *nexttiled(Client *c);
static Client *nthmaster(Client *c, int n, int reduce);
static Client *nthstack(Client *c, int n, int reduce);
static Client *nthtiled(Client *c, int n, int reduce);
static Client *inctiled(Client *c, int n);
static Client *prevtiled(Client *c);
static Client *prevsel(void);
static void swap(Client *a, Client *b);

static void stackfocus(const Arg *arg);
static void stackpush(const Arg *arg);
static void stackswap(const Arg *arg);
static Client *stackposclient(const Arg *arg);
