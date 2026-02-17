/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showsystray        = 1;        /* 0 means no systray */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 8;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, 0: display systray on the last monitor*/
static const unsigned int gappih    = 5;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;        /* vert inner gap between windows */
static const unsigned int gappoh    = 1;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 1;        /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "SFMono Nerd Font:size=7", "monospace:size=8" };
static const char col_gray1[]       = "#000000";
static const char col_gray2[]       = "#32302f";
static const char col_gray3[]       = "#a89984";
static const char col_gray4[]       = "#ebdbb2";
static const char col_accent[]        = "#98971a";
static const char col_red[]         = "#fb4934";
static const char col_orange[]      = "#fe8019";
static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
  [SchemeSel]  = { col_gray4, col_gray2,  col_accent  },

  [SchemeStatus]  = { col_gray4, col_gray1,  col_gray1  }, // Statusbar right {text,background,not used but cannot be empty}
  [SchemeTagsSel]  = { col_gray4, col_gray2,  col_gray1  }, // Tagbar left selected {text,background,not used but cannot be empty}
  [SchemeTagsNorm]  = { col_gray3, col_gray1,  col_gray1  }, // Tagbar left unselected {text,background,not used but cannot be empty}
  [SchemeInfoSel]  = { col_gray4, col_gray1,  col_gray1  }, // infobar middle  selected {text,background,not used but cannot be empty}
  [SchemeInfoNorm]  = { col_gray4, col_gray1,  col_gray1  }, // infobar middle  unselected {text,background,not used but cannot be empty}

  [SchemeScratchNorm] = { col_gray4, col_gray1,  col_orange },
  [SchemeScratchSel]  = { col_gray4, col_gray2,  col_red  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *defaulttagapps[] = { "firefox", "google-chrome-stable", "egui", "egui", "figma-linux", "virt-manager", NULL, NULL, NULL };

static const Rule rules[] = {
  /* xprop(1):
  *	WM_CLASS(STRING) = instance, class
  *	WM_NAME(STRING) = title
  *  WM_WINDOW_ROLE(STRING) = role
  */

  /* class      role,       instance    title       tags mask     isfloating   monitor    scratch key  isgame */
  { "ark",      NULL,       NULL,       NULL,       0,            0,           -1,       'e' },
  { "dolphin",  NULL,       NULL,       NULL,       0,            0,           -1,       'e' },
  { "spectacle", NULL,      NULL,       NULL,       0,            1,           -1,        0 },
  { "gwenview", NULL,       NULL,       NULL,       0,            1,           -1,        0 },
  { "Engrampa", NULL,       NULL,       NULL,       0,            0,           -1,       'e' },
  { "Ristretto", NULL,      NULL,       NULL,       0,            1,           -1,        0 },
  { "Nautilus", NULL,       NULL,       NULL,       0,            0,           -1,       'e' },
  { "Thunar",   NULL,       NULL,       NULL,       0,            0,           -1,       'e' },
  { NULL,       NULL,       "pcmanfm",  NULL,       0,            0,           -1,       'e' },
  { "feh",      NULL,       NULL,       NULL,       0,            1,           -1,        0 },
  { "firefox",  NULL,       "Places",   NULL,       0,            1,           -1,        0 },
  { NULL,       "pop-up",   NULL,       NULL,       0,            1,           -1,        0 },
  { NULL,       "quake",    NULL,       NULL,       0,            1,           -1,        0 },
  { NULL,       "GtkFileChooserDialog", NULL,	NULL, 0,          1,           -1,        0 },
  { "st-float", NULL,       NULL,       NULL,       0,            1,           -1,       'a' },
  { NULL,       NULL,       "emacs-float", NULL,    0,            1,           -1,       'a' },

  { "pavucontrol", NULL,    NULL,       NULL,       0,            1,           -1,       'a' },
  { "Qalculate",   NULL,    NULL,       NULL,       0,            1,           -1,       'a' },
  { "Gpick",       NULL,    NULL,       NULL,       0,            1,           -1,        0 },

  /* Graphics */
  { "Gimp",     NULL,       NULL,       NULL,       1 << 4,       0,           -1,        0 },
  { "krita",    NULL,       NULL,       NULL,       1 << 4,       0,           -1,        0 },
  { "figma",    NULL,       NULL,       NULL,       1 << 4,       0,           -1,        0 },

  /* Media */
  { "Spotify",  NULL,       NULL,       NULL,       0,            0,           -1,       'a' },
  { "Celluloid", NULL,      NULL,       NULL,       1 << 6,       0,           -1,        0 },
  { NULL,       NULL,       NULL,       "Haruna",   1 << 6,       0,           -1,        0 },
  { NULL,       NULL,       NULL,       "qBittorrent", 1 << 8,    0,           -1,       'a' },
  { "easyeffects", NULL,    NULL,       NULL,       0,            0,           -1,       'a' },

  /* Gaming */
  { "Lutris",   NULL,       NULL,       NULL,       0,            0,           -1,       'a' },
  { NULL,       NULL,       "steamwebhelper", NULL, 0,            0,           -1,       'a' },
  { "steam_app", NULL,      NULL,       NULL,       1 << 2,       0,           -1,        0,        1 },
  { "gw2-64.exe", NULL,     NULL,       NULL,       1 << 2,       0,           -1,        0,        1 },
  { "gw.exe",   NULL,       NULL,       NULL,       1 << 2,       0,           -1,        0,        1 },
  { "d2r.exe",  NULL,       NULL,       NULL,       1 << 2,       0,           -1,        0,        1 },
  { "explorer.exe", NULL,   NULL,       NULL,       1 << 2,       0,           -1,        0,        1 },

  /* VM */
  { "virt-manager", NULL,   NULL,       NULL,       1 << 5,       0,           -1,        0 },

  /* Scratchpads */
  { "spterm",   NULL,       NULL,       NULL,       0,            1,           -1,       'z' },
  { NULL,       NULL,       "spemacs",  NULL,       0,            1,           -1,       'x' },
  { "splf",     NULL,       NULL,       NULL,       0,            1,           -1,       'c' },
  { "spfm",     NULL,       NULL,       NULL,       0,            1,           -1,       'e' },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 60;  /* refresh rate (per second) for client move/resize */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "[M]",      monocle },
  { "D[]",      deck },
  { "><>",      NULL },    /* no layout function means floating */
  { NULL,       NULL },
};

static const MonitorRule monrules[] = {
  /* monitor  tag  layout  mfact  nmaster  showbar  topbar */
  /* {  1,       -1,  2,      -1,    -1,      -1,      -1     }, // use a different layout for the second monitor */
  {  -1,       5,  1,      -1,    -1,      -1,      -1     }, // tag 5, monocle
  {  -1,       6,  1,      -1,    -1,      -1,      -1     }, // tag 6, monocle
  {  -1,      -1,  0,      -1,    -1,      -1,      -1     }, // default
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,                    ACTION, {.i = INC(+1) } }, \
	{ MOD, XK_k,                    ACTION, {.i = INC(-1) } }, \
	{ MOD, XK_g,                    ACTION, {.i = PREVSEL } }, \
	{ MOD, XK_y,                    ACTION, {.i = MASTER(1) } }, \
	{ MOD, XK_o,                    ACTION, {.i = STACK(1) } },
	/* { MOD, XK_u,                    ACTION, {.i = MASTER(2) } }, \ */
	/* { MOD, XK_p,                    ACTION, {.i = STACK(2) } }, \ */
	/* { MOD, XK_n,                    ACTION, {.i = STACK(3) } }, \ */
	/* { MOD, XK_backslash,            ACTION, {.i = LASTTILED } }, */

#define SCRATCHKEYS(KEY,CMD) \
	{ MODKEY,                       KEY,      togglescratch,       {.v = CMD } }, \
	{ MODKEY|ShiftMask,             KEY,      setscratch,          {.v = CMD } }, \
	{ MODKEY|ControlMask,           KEY,      removescratch,       {.v = CMD } }, \

#define SEQKEYS(KEY,ACTION, CMD) \
	{0, KEY, ACTION, CMD}, \
	{MODKEY, KEY, ACTION, CMD}, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// Term
static const char *termcmd[]  = { "st", NULL };
/* static const char *termcmd[]  = { "alacritty", NULL }; */

// Dmenu
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, NULL};

// Rofi
static const char *roficmd[] = {
	"rofi",
	"-modi", "drun",
	"-show", "drun",
	"-show-icons",
	NULL
};

// Scratchpads
static const char *spcmd_z[] = {"z", "dwm-spterm", NULL};
static const char *spcmd_x[] = {"x", "dwm-spemacs", NULL};
static const char *spcmd_c[] = {"c", "dwm-splf", NULL};
static const char *spcmd_e[] = {"e", "dwm-spfm", NULL};
static const char *spcmd_a[] = {"a", NULL};

/* Resize mode */
static Key keyseq_resize[] = {
  SEQKEYS(XK_equal, setmfact, {.f = 1.55}) // Reset mfact
  SEQKEYS(XK_t,     setmfact, {.f = 1.55}) // Reset mfact
  SEQKEYS(XK_w,     setmfact, {.f = 1.69}) // Size of waydroid
  SEQKEYS(XK_e,     setmfact, {.f = 1.66}) // Size of emacs window
  SEQKEYS(XK_r,     spawn,    SHCMD("dwm-win-resize")) // Scratch
  SEQKEYS(XK_1,     spawn,    SHCMD("dwm-win-resize")) // Scratch
  SEQKEYS(XK_2,     spawn,    SHCMD("dwm-win-resize lg") ) // Scratch lg
  SEQKEYS(XK_3,     spawn,    SHCMD("dwm-win-resize xl") ) // Scratch xl
	{0},
};
	
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0}}, // Quit DWM
	/* { MODKEY,                       XK_b,      togglebar,      {0} }, */

	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ Mod1Mask,                     XK_F4,     killclient,     {0} },

	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ControlMask,           XK_d,      spawn,          {.v = roficmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD("egui") },
	{ MODKEY,                       XK_s,      spawndefault,   {0} },

	/* Utils */
	{ MODKEY|ShiftMask,             XK_c,      spawn,          SHCMD("my-colorpicker") },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          SHCMD("my-clipboard") },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          SHCMD("rofi-raindrop") },
	/* { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("$DOTFILES_BIN/pass") }, */
	{ MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("dmenu-translate") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("my-scrcpy") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("my-screenshot -r -s") },
	{ MODKEY,                       XK_p,      spawn,          SHCMD("tmux-sessionizer -s -d") },

	// Print screen
	{ MODKEY,                       XK_Print,  spawn,          SHCMD("my-screenshot -f -s") },
	{ MODKEY|ControlMask,           XK_Print,  spawn,          SHCMD("my-screenshot -a -s") },
	{ MODKEY|ShiftMask,             XK_Print,  spawn,          SHCMD("my-screenshot-dmenu") },

	// Volume control
	{ MODKEY,                       XK_minus,  spawn,          SHCMD("my-vol down") },
	{ MODKEY|ShiftMask,             XK_minus,  spawn,          SHCMD("my-vol mute") },
	{ MODKEY,                       XK_equal,  spawn,          SHCMD("my-vol up") },
	{ MODKEY|ShiftMask,             XK_equal,  spawn,          SHCMD("my-vol mute") },

	/* Focus */
	{ Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1 } }, // Focus next window
	{ Mod1Mask|ShiftMask,           XK_Tab,    focusstack,     {.i = -1 } }, // Focus prev window
	STACKKEYS(MODKEY,               stackfocus) // focus on the nth client in the stack
	{ MODKEY,                       XK_h,      focusdir,       {.i = 0 } }, // left
	{ MODKEY,                       XK_l,      focusdir,       {.i = 1 } }, // right

	/* Move */
	{ MODKEY|ShiftMask,             XK_h,      placedir,       {.i = 0 } }, // left
	{ MODKEY|ShiftMask,             XK_l,      placedir,       {.i = 1 } }, // right
	STACKKEYS(MODKEY|ShiftMask,                stackswap)  // swap the currently focused client with the nth client in the stack
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_BackSpace, zoom,        {0} },

	/* Resize */
	{ MODKEY,                       XK_r,      keypress_other, {.v = keyseq_resize}},
	// mfact
	{ MODKEY|ControlMask,           XK_h,      setmfact,       {.f = -0.01} },
	{ MODKEY|ControlMask,           XK_l,      setmfact,       {.f = +0.01} },
	// cfact
	{ MODKEY|ControlMask,           XK_k,      setcfact,       {.f = +0.10} },
	{ MODKEY|ControlMask,           XK_j,      setcfact,       {.f = -0.10} },
	{ MODKEY|ControlMask,           XK_o,      setcfact,       {.f =  0.00} },

	/* Layouts */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_w,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[3]} },
	// cycle
	{ MODKEY|ControlMask,           XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	// toggle float
	{ MODKEY,                       XK_f,      togglefloating, {0} },
	// fullscreen
	{ MODKEY,                       XK_m,      togglefullscreen, {0} },
	{ MODKEY|ShiftMask,             XK_m,      togglefakefullscreen, {0} },

	/* Switching monitors */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* Scratchpads */
	SCRATCHKEYS(XK_z, spcmd_z)
	SCRATCHKEYS(XK_x, spcmd_x)
	{ MODKEY,                       XK_c,      togglescratch,  {.v = spcmd_c } },
	SCRATCHKEYS(XK_e, spcmd_e)
	SCRATCHKEYS(XK_a, spcmd_a)

	/* Switching tags */
	{ MODKEY,                       XK_grave,  view,          {0}},
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } }, // View all tags
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, // Show window on all tags

	{0}
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[3]} },

	{ ClkStatusText,        0,              Button1,        spawn,          {.v = dmenucmd } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = roficmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = termcmd } },

	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button3,      dragcfact,      {0} },

	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
