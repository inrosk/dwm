/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1;        /* border pixel of windows */
static const unsigned int snap = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 8;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const unsigned int gappih = 5;
static const unsigned int gappiv = 5;
static const unsigned int gappoh = 1;
static const unsigned int gappov = 1;
static const int smartgaps = 1;
static const int showsystray = 1;     /* 0 means no systray */
static const int showbar = 1;        /* 0 means no bar */
static const int topbar = 1;        /* 0 means bottom bar */
static const char *fonts[] = { "SFMono Nerd Font:size=7", "FiraCode Nerd Font:size=8", "monospace:size=10" };
static const char bg_normal[] = "#000000";
static const char bg_sel[] = "#32302f";
static const char fg_normal[] = "#a89984";
static const char fg_sel[] = "#ebdbb2";
static const char col_accent[] = "#98971a";
static const char *colors[][3] = {
	/*               fg         bg          border   */
	[SchemeNorm] = { fg_normal, bg_normal, bg_normal },
	[SchemeSel] = { fg_sel, bg_sel, col_accent  },

	[SchemeStatus] = { fg_sel, bg_normal, bg_normal }, // Statusbar right {text, background, border not used but cannot be empty}
	[SchemeTagsSel] = { fg_sel, bg_sel, bg_sel }, // Tagbar left selected {text, background, border not used but cannot be empty}
	[SchemeTagsNorm] = { fg_normal, bg_normal, bg_normal }, // Tagbar left unselected {text, background, border not used but cannot be empty}
	[SchemeInfoSel] = { fg_sel, bg_normal, bg_normal }, // infobar middle  selected {text, background, border not used but cannot be empty}
	[SchemeInfoNorm] = { fg_sel, bg_normal, bg_normal }, // infobar middle  unselected {text, background, border not used but cannot be empty}
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd0[] = { "sh", "-c", "$DOTFILES_BIN/dwm/scratch-term", NULL };
const char *spcmd1[] = { "sh", "-c", "$DOTFILES_BIN/dwm/scratch-emacs", NULL };
const char *spcmd2[] = { "sh", "-c", "$DOTFILES_BIN/dwm/scratch-lf", NULL };
const char *spcmd3[] = { "sh", "-c", "$DOTFILES_BIN/dwm/scratch-thunar", NULL };
/* const char *spcmd1[] = {"alacritty", "--class", "spterm", "-o", "window.dimensions.columns=120", "-o", "window.dimensions.lines=38", "-e", "tmux", "new-session", "-A", "-s", "spterm", NULL }; */
/* const char *spcmd2[] = {"emacsclient", "-n", "-c", "--frame-parameters='(quote (name . \"scratchmacs\"))'", NULL }; */
/* const char *spcmd3[] = {"alacritty", "--class", "splf", "-o", "window.dimensions.columns=120", "-o", "window.dimensions.lines=38", "-e", "tmux", "new-session", "-A", "-s", "splf", "lfrun", NULL }; */
/* const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL }; */
/* const char *spcmd3[] = {"keepassxc", NULL }; */
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",       spcmd0},
	{"scratchmacs",  spcmd1},
	{"splf",         spcmd2},
	{"spthunar",     spcmd3},
	/* {"keepassxc",    spcmd3}, */
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *defaulttagapps[] = { "firefox", "google-chrome-stable", "alacritty", "emacs", "figma-linux", "steam", "dmenu_run", "virt-manager", "dmenu_run" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
      WM_WINDOW_ROLE(STRING) = role
	 */
	/* class      role        instance    title       tags mask     isfloating   monitor */
	{ "ark",      NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "Characters", NULL,     NULL,       NULL,       0,            1,           -1 },
	{ "dolphin",  NULL,       NULL,       NULL,       0,            1,           -1 },
	{ NULL,       NULL,       NULL, "Emoji Selector", 0,            1,           -1 },
	{ "Engrampa", NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "feh",      NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "firefox",  NULL,       "Places",   NULL,       0,            1,           -1 },
	{ "gnome-system-monitor", NULL, NULL, NULL,       0,            1,           -1 },
	{ "Gpick",    NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "gwenview", NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "FileRoller", NULL,     NULL,       NULL,       0,            1,           -1 },
	{ "kcalc",    NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "kclock",   NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "Loupe",    NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "Nautilus", NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "pavucontrol", NULL,    NULL,       NULL,       0,            1,           -1 },
	{ "pwvucontrol", NULL,    NULL,       NULL,       0,            1,           -1 },
	{ "Qalculate", NULL,      NULL,       NULL,       0,            1,           -1 },
	{ "Ristretto", NULL,      NULL,       NULL,       0,            1,           -1 },
	{ "spectacle", NULL,      NULL,       NULL,       0,            1,           -1 },
	{ "Thunar",   NULL,       NULL,       NULL,       0,            1,           -1 },
	{ "vimiv",    NULL,       NULL,       NULL,       0,            1,           -1 },
	{ NULL,       "pop-up",   NULL,       NULL,       0,            1,           -1 },
	{ NULL,       "quake",    NULL,       NULL,       0,            1,           -1 },
	{ NULL,       "GtkFileChooserDialog", NULL,	NULL, 0,				    1,           -1 },

	/* Graphics */
	{ "Gimp",     NULL,       NULL,       NULL,       1 << 4,       0,           -1 },
	{ "krita",    NULL,       NULL,       NULL,       1 << 4,       0,           -1 },
	{ "Inkscape", NULL,       NULL,       NULL,       1 << 4,       0,           -1 },
	{ "figma",    NULL,       NULL,       NULL,       1 << 4,       0,           -1 },

	/* Games */
	{ "Lutris",   NULL,       NULL,       NULL,       1 << 5,       0,           -1 },
	{ NULL,       NULL,       "steamwebhelper", NULL, 1 << 5,       0,           -1 },
	{ "d2r.exe",   NULL,      NULL,       NULL,       1 << 6,       1,           -1 },
	{ "gw.exe",   NULL,       NULL,       NULL,       1 << 6,       1,           -1 },
	{ "steam_app_1284210", NULL, NULL,    NULL,       1 << 6,       1,           -1 },
	{ "gw2-64.exe", NULL,     NULL,       NULL,       1 << 6,       1,           -1 },
	{ "explorer.exe", NULL,   NULL,       NULL,       1 << 6,       1,           -1 },
	{ "battle.net.exe", NULL, NULL,       NULL,       1 << 5,       1,           -1 },
	{ "overwatch.exe", NULL,  NULL,       NULL,       1 << 6,       1,           -1 },

	/* Media */
	{ "Celluloid", NULL,      NULL,       NULL,       1 << 7,       0,           -1 },
	{ NULL,       NULL,       NULL,       "Haruna",   1 << 7,       0,           -1 },
	{ NULL,       NULL,       NULL,    "qBittorrent", 1 << 8,       0,           -1 },
	{ "easyeffects", NULL,    NULL,       NULL,       1 << 8,       0,           -1 },

	/* VM */
	{ "virt-manager", NULL,   NULL,       NULL,       1 << 7,       0,           -1 },

	/* Scratchpad */
	{ NULL,	      NULL,       "spterm",   NULL,		    SPTAG(0),			  1,			   -1 },
	{ NULL,	      NULL,       "scratchmacs", NULL,    SPTAG(1),		    1,	       -1 },
	{ NULL,	      NULL,       "splf",	    NULL,		    SPTAG(2),			 	1,	       -1 },
	{ "spthunar",	NULL,       NULL,	      NULL,		    SPTAG(3),			 	1,	       -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	/* { "[@]",      spiral }, */
	/* { "[\\]",     dwindle }, */
	/* { "H[]",      deck }, */
	/* { "TTT",      bstack }, */
	/* { "===",      bstackhoriz }, */
	/* { "HHH",      grid }, */
	/* { "###",      nrowgrid }, */
	/* { "---",      horizgrid }, */
	/* { ":::",      gaplessgrid }, */
	/* { "|M|",      centeredmaster }, */
	/* { ">M>",      centeredfloatingmaster }, */
	{ NULL,       NULL },
};

static const MonitorRule monrules[] = {
	/* monitor, tag, layout  mfact  nmaster  showbar  topbar */
	/* {1,      -1,  2,      -1,    -1,      -1,      -1     }, // use a different layout for the second monitor */
	{  -1,       4,  0,      -1,    -1,      -1,      -1     },
	{  -1,       5,  1,      -1,    -1,      -1,      -1     },
	{  -1,       7,  2,      -1,    -1,      -1,      -1     },
	{  -1,       8,  1,      -1,    -1,      -1,      -1     },
	{  -1,      -1,  0,      -1,    -1,      -1,      -1     }, // default
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* If you are using the standard dmenu program, use the following. */
static const char *dmenucmd[]    = { "dmenu_run", "-p", "Run: ", NULL };
static const char *roficmd[] = { "rofi", "-modi", "drun", "-show", "drun", "-show-icons", NULL };
/* commands */
static const char *termcmd[]  = { "alacritty", NULL };

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = roficmd } }, // Rofi
	{ Mod1Mask,                     XK_space,  spawn,          {.v = dmenucmd } }, // Dmenu
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } }, // Launch terminal
	{ MODKEY,                       XK_s,      spawndefault,   {0} }, // Spawn favorite app per tag
	{ MODKEY,                       XK_q,      killclient,     {0} }, // Kill window
	{ Mod1Mask,                     XK_F4,     killclient,     {0} }, // Kill window
	{ MODKEY|ShiftMask,				      XK_r,      spawn,		       SHCMD("$DOTFILES_BIN/dwm/resize-window")}, // Resize window

	/* Focus */
	{ Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1 } }, // Focus next window
	{ Mod1Mask|ShiftMask,           XK_Tab,    focusstack,     {.i = -1 } }, // Focus prev window

	{ MODKEY,                       XK_h,      focusstack,     {.i = -1 } }, // Focus prev window
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } }, // Focus next window
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, // Focus prev window
	{ MODKEY,                       XK_l,      focusstack,     {.i = +1 } }, // Focus next window

	/* Move */
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } }, // Move window down
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } }, // Move window up
	{ MODKEY,                       XK_BackSpace, zoom,        {0} }, // Promote to master
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } }, // Increase number of windows in master area
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } }, // Reduce number of windows in master area

	/* Resize */
	{ MODKEY|ControlMask,           XK_l,      setmfact,       {.f = +0.01} }, // Increase size of master area
	{ MODKEY|ControlMask,           XK_h,      setmfact,       {.f = -0.01} }, // Reduce size of master area

	{ MODKEY,                      XK_KP_Insert, setmfact,     {.f = 1.55} }, // 0 Reset the size of master area
	{ MODKEY,                      XK_KP_End,   setmfact,      {.f = 1.69} }, // 1 Size for waydroid
	{ MODKEY,                      XK_KP_Down,  setmfact,      {.f = 1.66} }, // 2 Size for emacs window
	{ MODKEY,                      XK_KP_Home, spawn,          SHCMD("$DOTFILES_BIN/dwm/resize-window")}, // 7 Scratch
	{ MODKEY,                      XK_KP_Up,   spawn,          SHCMD("$DOTFILES_BIN/dwm/resize-window lg") }, // 8 Scratch-lg
	{ MODKEY,                      XK_KP_Prior, spawn,         SHCMD("$DOTFILES_BIN/dwm/resize-window xl") }, // 9 Scratch-xl

	/* Leyout manipulation */
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[0]} }, // Set tile layout
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // Set tile layout
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[1]} }, // Set monocle layout
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[2]} }, // Set floating layout
	{ MODKEY,                       XK_f,      togglefloating, {0} }, // Toggle window floating
	{ MODKEY,                       XK_m,      togglefullscr,  {0} }, // Toggle fullscreen

	/* Scratchpads */
	{ MODKEY,            			      XK_z,			 togglescratch,  {.ui = 0 } },
	{ MODKEY,            			      XK_x,			 togglescratch,  {.ui = 1 } },
	{ MODKEY,            			      XK_c,	     togglescratch,  {.ui = 2 } },
	{ MODKEY,            			      XK_v,	     togglescratch,  {.ui = 3 } },

	/* Switching between monitors */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },


	/* Volume control */
	{ MODKEY,                       XK_minus,  spawn,          SHCMD("set-vol down") },
	{ MODKEY,                       XK_equal,  spawn,          SHCMD("set-vol up") },

	/* { MODKEY,                       XK_minus, spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -1%; pkill -RTMIN+10 dwmblocks") }, */
	/* { MODKEY,                       XK_equal, spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +1%; pkill -RTMIN+10 dwmblocks") }, */

	/* Clipmenu */
	{ MODKEY,                       XK_semicolon, spawn,      SHCMD("CM_LAUNCHER=rofi clipmenu -i") },

	/* Switching between tags */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_grave,  view,           {0} }, /* Switch to last tag */

	/* Quitting dwm */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

	/* Useless */
	{ MODKEY,                       XK_b,      togglebar,      {0} }, // Toggle bar
	{ MODKEY,                       XK_Insert, togglegaps,     {0} }, // Toggle gaps
	{ MODKEY|ShiftMask,             XK_Insert, defaultgaps,    {0} }, // Default gaps
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } }, // View all tags
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, // Show window on all tags
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
