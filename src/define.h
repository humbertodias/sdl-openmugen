#ifndef __DEFINE__H
#define __DEFINE__H

#define MAXCOMMAND 30

//
const int INSPERTRIGGER = 40;
const int INSPerConParam = 100;
const int ConParmPerState = 40;
const int ConHDParmPerState = 40;
const int NUMTRIGGER = 20;
const int PARAMS = 10;
const int T_TRIGGERALL = 192;
// 没有参数
const int NOPARAM = -333;

//#define MAX_PATH 255

enum {
	MAINMENU=0,
	STAGE=1,
	ENGINE=2,
	P1=3,
	P2=4,
	P3=5,
	P4=6
};



//Define  Controller buttoms
enum KEY_NAMES
{
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_BUTTON_A,
	KEY_BUTTON_B,
	KEY_BUTTON_C,
	KEY_BUTTON_X,
	KEY_BUTTON_Y,
	KEY_BUTTON_Z,
	KEY_BUTTON_START,
	KEY_BUTTON_PAUSE,
	KEY_COUNT
};


// 操作标识符
enum OPCODES
{
	OP_PUSH=0,
	OP_POP,
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_EQUAL,
	OP_NOTEQUAL,
	OP_LESS,
	OP_GREATER,
	OP_LESSEQUAL,
	OP_GRAETEREQUAL,
	OP_INTERVALOP1,
	OP_INTERVALOP2,
	OP_INTERVALOP3,
	OP_INTERVALOP4,
	OP_INTERVALOP5,
	OP_INTERVALOP6,
	OP_INTERVALOP7,
	OP_INTERVALOP8,
	OP_LOGNOT,
	OP_LOGAND,
	OP_LOGOR,
	OP_LOGXOR,
	OP_NOT,
	OP_AND,
	OP_OR,
	OP_XOR,
	OP_SQUARE,
	OP_NEG,


	OP_Abs,
	OP_Acos,
	OP_Alive,
	OP_Anim,
	OP_AnimElem,
	OP_AnimElemNo,
	OP_AnimElemTime,
	OP_AnimExist,
	OP_AnimTime,
	OP_Asin,
	OP_Atan,
	OP_AuthorName,
	OP_BackEdgeBodyDist,
	OP_BackEdgeDist,
	OP_CanRecover,
	OP_Ceil,
	OP_Command,
	OP_Const,
	OP_Cos,
	OP_Ctrl,
	OP_DrawGame,
	OP_E,
	OP_Exp,
	OP_Facing,
	OP_Floor,
	OP_FrontEdgeBodyDist,
	OP_FrontEdgeDist,
	OP_FVar,
	OP_GameTime,
	OP_GetHitVar,
	OP_HitCount,
	OP_HitDefAttr,
	OP_HitFall,
	OP_HitOver,
	OP_HitPauseTime,
	OP_HitShakeOver,
	OP_HitVel,
	OP_ID,
	OP_IfElse,
	OP_InGuardDist,
	OP_IsHelper,
	OP_IsHomeTeam,
	OP_Life,
	OP_LifeMax,
	OP_Log,
	OP_Ln,
	OP_Lose,
	OP_MatchNo,
	OP_MatchOver,
	OP_MoveContact,
	OP_MoveGuarded,
	OP_MoveHit,
	OP_MoveType,
	OP_MoveReversed,
	OP_Name,
	OP_NumEnemy,
	OP_NumExplod,
	OP_NumHelper,
	OP_NumPartner,
	OP_NumProj,
	OP_NumProjID,
	OP_NumTarget,
	OP_P1Name,
	OP_P2BodyDist,
	OP_P2Dist,
	OP_P2Life,
	OP_P2MoveType,
	OP_P2Name,
	OP_P2StateNo,
	OP_P2StateType,
	OP_P3Name,
	OP_P4Name,
	OP_PalNo,
	OP_ParentDist,
	OP_Pi,
	OP_Pos,
	OP_Power,
	OP_PowerMax,
	OP_PlayerIDExist,
	OP_PrevStateNo,
	OP_ProjCancelTime,
	OP_ProjContact,
	OP_ProjContactTime,
	OP_ProjGuarded,
	OP_ProjGuardedTime,
	OP_ProjHit,
	OP_ProjHitTime,
	OP_Random,
	OP_RootDist,
	OP_RoundNo,
	OP_RoundsExisted,
	OP_RoundState,
	OP_ScreenPos,
	OP_SelfAnimExist,
	OP_Sin,
	OP_StateNo,
	OP_StateType,
	OP_SysFVar,
	OP_SysVar,
	OP_Tan,
	OP_TeamMode,
	OP_TeamSide,
	OP_TicksPerSecond,
	OP_Time,
	OP_TimeMod,
	OP_UniqHitCount,
	OP_Var,
	OP_Vel,
	OP_Win,
	OP_MOD,
	OP_NOP,
	OP_STOP,

};


//All triggers       
static char * strTriggerType[] = {
	"Abs",
	"Acos",
	"Alive",
	"Anim",
	"AnimElem",
	"AnimElemNo",
	"AnimElemTime",
	"AnimExist",
	"AnimTime",
	"Asin",
	"Atan",
	"AuthorName",
	"BackEdgeBodyDist",
	"BackEdgeDist",
	"CanRecover",
	"Ceil",
	"Command",
	"Const",
	"Cos",
	"Ctrl",
	"DrawGame",
	"E",
	"Exp",
	"Facing",
	"Floor",
	"FrontEdgeBodyDist",
	"FrontEdgeDist",
	"FVar",
	"GameTime",
	"GetHitVar",
	"HitCount",
	"HitDefAttr",
	"HitFall",
	"HitOver",
	"HitPauseTime",
	"HitShakeOver",
	"HitVel",
	"ID",
	"IfElse",
	"InGuardDist",
	"IsHelper",
	"IsHomeTeam",
	"Life",
	"LifeMax",
	"Log",
	"Ln",
	"Lose",
	"MatchNo",
	"MatchOver",
	"MoveContact",
	"MoveGuarded",
	"MoveHit",
	"MoveType",
	"MoveReversed",
	"Name",
	"NumEnemy",
	"NumExplod",
	"NumHelper",
	"NumPartner",
	"NumProj",
	"NumProjID",
	"NumTarget",
	"P1Name",
	"P2BodyDist",
	"P2Dist",
	"P2Life",
	"P2MoveType",
	"P2Name",
	"P2StateNo",
	"P2StateType",
	"P3Name",
	"P4Name",
	"PalNo",
	"ParentDist",
	"Pi",
	"Pos",
	"Power",
	"PowerMax",
	"PlayerIDExist",
	"PrevStateNo",
	"ProjCancelTime",
	"ProjContact",
	"ProjContactTime",
	"ProjGuarded",
	"ProjGuardedTime",
	"ProjHit",
	"ProjHitTime",
	"Random",
	"RootDist",
	"RoundNo",
	"RoundsExisted",
	"RoundState",
	"ScreenPos",
	"SelfAnimExist",
	"Sin",
	"StateNo",
	"StateType",
	"SysFVar",
	"SysVar",
	"Tan",
	"TeamMode",
	"TeamSide",
	"TicksPerSecond",
	"Time",
	"TimeMod",
	"UniqHitCount",
	"Var",
	"Vel",
	"Win",
	0,
};

// 游戏自定义变量
enum PARAMVALUES
{
	PA_VALUE=128,
	PA_XVALUE,
	PA_YVALUE,
	PA_VAR,
	PA_FVAR,
	PA_SYSVAR,
	PA_SYSFVAR,


};

//This are all documented Controllers
//TODO: find the undocumented controllers
static char* strControllerTypes[] = {
	"AfterImage",
	"AfterImageTime",
	"AllPalFX",
	"AngleAdd",
	"AngleDraw",
	"AngleMul",
	"AngleSet",
	"AppendToClipboard",
	"AssertSpecial",
	"AttackDist",
	"AttackMulSet",
	"BGPalFX",
	"BindToParent",
	"BindToRoot",
	"BindToTarget",
	"ChangeAnim",
	"ChangeAnim2",
	"ChangeState",
	"ClearClipboard",
	"CtrlSet",
	"DefenceMulSet",
	"DestroySelf",
	"DisplayToClipboard",
	"EnvColor",
	"EnvShake",
	"Explod",
	"ExplodBindTime",
	"ForceFeedback",
	"FallEnvShake",
	"GameMakeAnim",
	"Gravity",
	"Helper",
	"HitAdd",
	"HitBy",
	"HitDef",
	"HitFallDamage",
	"HitFallSet",
	"HitFallVel",
	"HitOverride",
	"HitVelSet",
	"LifeAdd",
	"LifeSet",
	"MakeDust",
	"ModifyExplod",
	"MoveHitReset",
	"NotHitBy",
	"Null",
	"Offset",
	"PalFX",
	"ParentVarAdd",
	"ParentVarSet",
	"Pause",
	"PlayerPush",
	"PlaySnd",
	"PosAdd",
	"PosFreeze",
	"PosSet",
	"PowerAdd",
	"PowerSet",
	"Projectile",
	"RemoveExplod",
	"ReversalDef",
	"ScreenBound",
	"SelfState",
	"SprPriority",
	"StateTypeSet",
	"SndPan",
	"StopSnd",
	"SuperPause",
	"TargetBind",
	"TargetDrop",
	"TargetFacing",
	"TargetLifeAdd",
	"TargetPowerAdd",
	"TargetState",
	"TargetVelAdd",
	"TargetVelSet",
	"Trans",
	"Turn",
	"VarAdd",
	"VarRandom",
	"VarRangeSet",
	"VarSet",
	"VelAdd",
	"VelMul",
	"VelSet",
	"Width",
	0,
};

enum{
	Control_AfterImage =0,
	Control_AfterImageTime,
	Control_AllPalFX,
	Control_AngleAdd,
	Control_AngleDraw,
	Control_AngleMul,
	Control_AngleSet,
	Control_AppendToClipboard,
	Control_AssertSpecial,
	Control_AttackDist,
	Control_AttackMulSet,
	Control_BGPalFX,
	Control_BindToParent,
	Control_BindToRoot,
	Control_BindToTarget,
	Control_ChangeAnim,
	Control_ChangeAnim2,
	Control_ChangeState,
	Control_ClearClipboard,
	Control_CtrlSet,
	Control_DefenceMulSet,
	Control_DestroySelf,
	Control_DisplayToClipboard,
	Control_EnvColor,
	Control_EnvShake,
	Control_Explod,
	Control_ExplodBindTime,
	Control_ForceFeedback,
	Control_FallEnvShake,
	Control_GameMakeAnim,
	Control_Gravity,
	Control_Helper,
	Control_HitAdd,
	Control_HitBy,
	Control_HitDef,
	Control_HitFallDamage,
	Control_HitFallSet,
	Control_HitFallVel,
	Control_HitOverride,
	Control_HitVelSet,
	Control_LifeAdd,
	Control_LifeSet,
	Control_MakeDust,
	Control_ModifyExplod,
	Control_MoveHitReset,
	Control_NotHitBy,
	Control_Null,
	Control_Offset,
	Control_PalFX,
	Control_ParentVarAdd,
	Control_ParentVarSet,
	Control_Pause,
	Control_PlayerPush,
	Control_PlaySnd,
	Control_PosAdd,
	Control_PosFreeze,
	Control_PosSet,
	Control_PowerAdd,
	Control_PowerSet,
	Control_Projectile,
	Control_RemoveExplod,
	Control_ReversalDef,
	Control_ScreenBound,
	Control_SelfState,
	Control_SprPriority,
	Control_StateTypeSet,
	Control_SndPan,
	Control_StopSnd,
	Control_SuperPause,
	Control_TargetBind,
	Control_TargetDrop,
	Control_TargetFacing,
	Control_TargetLifeAdd,
	Control_TargetPowerAdd,
	Control_TargetState,
	Control_TargetVelAdd,
	Control_TargetVelSet,
	Control_Trans,
	Control_Turn,
	Control_VarAdd,
	Control_VarRandom,
	Control_VarRangeSet,
	Control_VarSet,
	Control_VelAdd,
	Control_VelMul,
	Control_VelSet,
	Control_Width,

};



// control中设置的属性枚举，相关的是一个表达式，不直接赋值
enum ConParmName
{
	CPN_value = 1,
	CPN_emem,
	CPN_anim,
	CPN_ctrl,
	CPN_x,
	CPN_y,
};

// control HItDef中设置的属性枚举，相关的是一个表达式，不直接赋值
enum CONTROLHITDEFParmName
{
	CHD_attr = 1,
	CHD_hitflag,
	CHD_guardflag,
	CHD_affectteam,
	CHD_animtype,
	CHD_air_animtype,
	CHD_fall_animtype,
	CHD_priority,
	CHD_damage,
	CHD_pausetime,
	CHD_guard_pausetime,
	CHD_sparkno,
	CHD_guard_sparkno,
	CHD_sparkxy,
	CHD_hitsound,
	CHD_guardsound,
	CHD_ground_type,
	CHD_air_type,
	CHD_ground_slidetime,
	CHD_guard_slidetime,
	CHD_ground_hittime,
	CHD_guard_hittime,
	CHD_air_hittime ,
	CHD_guard_ctrltime,
	CHD_guard_dist,
	CHD_yaccel,
	CHD_ground_velocity,
	CHD_guard_velocity ,
	CHD_air_velocity,
	CHD_airguard_velocity,
	CHD_ground_cornerpush_veloff,
	CHD_air_cornerpush_veloff,
	CHD_down_cornerpush_veloff,
	CHD_guard_cornerpush_veloff,
	CHD_airguard_cornerpush_veloff,
	CHD_airguard_ctrltime,
	CHD_air_juggle,
	CHD_mindist,
	CHD_maxdist,
	CHD_snap,
	CHD_p1sprpriority,
	CHD_p2sprpriority,
	CHD_p1facing,
	CHD_p1getp2facing,
	CHD_p2facing,
	CHD_p1stateno,
	CHD_p2stateno,
	CHD_p2getp1state,
	CHD_forcestand,
	CHD_fall,
	CHD_fall_xvelocity,
	CHD_fall_yvelocity,
	CHD_fall_recover,
	CHD_fall_recovertime,
	CHD_fall_damage,
	CHD_air_fall,
	CHD_forcenofall,
	CHD_down_velocity,
	CHD_down_hittime,
	CHD_down_bounce,
	CHD_id,
	CHD_chainID,
	CHD_nochainID,
	CHD_hitonce,
	CHD_kill,
	CHD_guard_kill,
	CHD_fall_kill,
	CHD_numhits,
	CHD_getpower,
	CHD_givepower,
	CHD_palfx_time,
	CHD_palfx_mul,
	CHD_palfx_add,
	CHD_envshake_time,
	CHD_envshake_freq,
	CHD_envshake_ampl,
	CHD_envshake_phase,
	CHD_fall_envshake_time,
	CHD_fall_envshake_freq,
	CHD_fall_envshake_ampl,
	CHD_fall_envshake_phase,
};


//StateTypes
enum Types
{
	stand=0,
	crouch,
	air,
	liedown,
	attack,
	idle,
	hit,
	none,
	untouch
};


//FlipFlags for air manager
// 读取air文件时候使用
enum FlipFlag
{
	HFLIPFLAG=1,
	VFLIPFLAG=2,
	HVFLIPFLAG=3

};


// 攻击时候自己的状态
enum HitDef_Attr_SelfType_Enum
{
	HitDef_Attr_SelfType_Stand=0,
	HitDef_Attr_SelfType_Crouch,
	HitDef_Attr_SelfType_Aerial
};
static char HitDef_Attr_SelfType[] = {'S','C','A'};

// 攻击的等级
enum HitDef_Attr_LevelType_Enum
{
	HitDef_Attr_AtkLevel_Normal=0,
	HitDef_Attr_AtkLevel_Special,
	HitDef_Attr_AtkLevel_Hyper
};
static char HitDef_Attr_LevelType[] = {'N','S','H'};


// 攻击类型
enum HitDef_Attr_AtkType_Enum
{
	HitDef_Attr_AtkType_Attack=0,
	HitDef_Attr_AtkType_Throw,
	HitDef_Attr_AtkType_Projectile
};
static char HitDef_Attr_AtkType[] = {'A','T','P'};


// const枚举
static char* strConstType[] = {
	"Data.life",
	0,
};

enum ConstType_Enum
{
	Const_Data_Life=0,
};


#endif
