#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H

/*
 * 功能：消息枚举值
 * 编写时间：2013-04-13
 */

class MessageType
{
   public:
    enum MsgTypeEnum {

        /*
             * 枚举变量的使用说明:以界面为单位,每一个界面分配20个枚举变量,
             * 以"s+数字"形式的表示当前没有使用,
             * 正式使用时一定不能使用"s+数字"的形式来进行枚举值的命名
             */
            //特殊使用的枚举值
            defaultOption,  //用于将服务线程进入到wait状态
            notFindFreeServerThread,//没有找到空闲的服务线程

            //AllHostNameAndMOR.java类使用
            GetAllHostName,  //获取所有主机名称
            GetAllHostMOR,   //获取全部主机的MOR
            GetAllHostNameAndMOR,//获取全部主机的名称和MOR
            s4,
            s5,
            s6,
            s7,
            s8,
            s9,
            s10,
            s11,
            s12,
            s13,
            s14,
            s15,
            s16,
            s17,
            s18,
            s19,
            s20,

            //VMNameAndState.java类使用
            GetVMNameAndState,  //获取指定host下的全部虚拟机名称和状态
            s22,
            s23,
            s24,
            s25,
            s26,
            s27,
            s28,
            s29,
            s30,
            s31,
            s32,
            s33,
            s34,
            s35,
            s36,
            s37,
            s38,
            s39,
            s40,

            //HostInfo.java类使用
            GetHostInfo,  //获取指定主机的详情信息
            s42,
            s43,
            s44,
            s45,
            s46,
            s47,
            s48,
            s49,
            s50,
            s51,
            s52,
            s53,
            s54,
            s55,
            s56,
            s57,
            s58,
            s59,

            //VirtualMachineInfo.java类使用
            GetVirtualMachineInfo,  //获取指定主机下的虚拟机详情信息
            s61,
            s62,
            s63,
            s64,
            s65,
            s66,
            s67,
            s68,
            s69,
            s70,
            s71,
            s72,
            s73,
            s74,
            s75,
            s76,
            s77,
            s78,
            s79,

            //DatastoresByHost.java使用
            GetDataStores,  //获取指定主机下的全部的存储器
            GetDataStoresSubForder,  //显示存储器的下一级文件夹
            s82,
            s83,
            s84,
            s85,
            s86,
            s87,
            s88,
            s89,
            s90,
            s91,
            s92,
            s93,
            s94,
            s95,
            s96,
            s97,
            s98,
            s99,

            //IsoFile.java使用
            GetIsoFile,  //获取全部镜像文件
            s101,
            s102,
            s103,
            s104,
            s105,
            s106,
            s107,
            s108,
            s109,
            s110,
            s111,
            s112,
            s113,
            s114,
            s115,
            s116,
            s117,
            s118,
            s119,

            //OtherInformation.java使用
            GetGuestOsId,  //获取客户机操作类型
            GetvMotionPriority,//获取迁移优先级
            s122,
            s123,
            s124,
            s125,
            s126,
            s127,
            s128,
            s129,
            s130,
            s131,
            s132,
            s133,
            s134,
            s135,
            s136,
            s137,
            s138,
            s139,


            // HostOperation.java类使用
            AddHostToCluster, // 添加主机到集群
            RemoveHostFromCluster, // 将主机从集群中移除
            EnterMaintenanceMode, // 将主机进入维护模式
            ExitMaintenanceMode, // 将主机退出维护模式
            DisconnectHost, // 断开与主机的连接
            ReconnectHost, // 重新与主机进行连接
            s146,
            s147,
            s148,
            s149,
            s150,
            s151,
            s152,
            s153,
            s154,
            s155,
            s156,
            s157,
            s158,
            s159,

            //VMClone.java使用
            CloneVM,  //克隆虚拟机(开机或关机)
            CloneTemplate, //克隆模板 (模板是虚拟机的主镜像)
            CloneVMToTemplate, //虚拟机克隆为模板
            CloneTemplatToVM, // 从模板部署虚拟机
            VmToTemp, //将虚拟机转化为模板
            MarkAsVM, //将模板转化为虚拟机
            s166,
            s167,
            s168,
            s169,
            s170,
            s171,
            s172,
            s173,
            s174,
            s175,
            s176,
            s177,
            s178,
            s179,

            //VMCreate.java使用
            CreateVirtualMachine, //创建虚拟机
            s181,
            s182,
            s183,
            s184,
            s185,
            s186,
            s187,
            s188,
            s189,
            s190,
            s191,
            s192,
            s193,
            s194,
            s195,
            s196,
            s197,
            s198,
            s199,

            //VMOtherOps.java使用
            DestroyVm,  //删除虚拟机
            UnregisterVm,  //从清单中移除虚拟机
            RenameVm,  //虚拟机重命名
            s203,
            s204,
            s205,
            s206,
            s207,
            s208,
            s209,
            s210,
            s211,
            s212,
            s213,
            s214,
            s215,
            s216,
            s217,
            s218,
            s219,

            //VMotion.java使用
            MigrateVM,  //对虚拟机进行迁移操作
            RelocateVMOnSameHost,  //对虚拟机在同一主机内进行重定位操作
            RelocateVMOnDifferentHost,  //对虚拟机在不同主机内进行重定位操作
            s223,
            s224,
            s225,
            s226,
            s227,
            s228,
            s229,
            s230,
            s231,
            s232,
            s233,
            s234,
            s235,
            s236,
            s237,
            s238,
            s239,

            //VMPowerOps.java使用
            PowerOnVM,  //给指定的虚拟机打开电源
            PowerOffVM,  //给指定的虚拟机关闭电源
            ResetVM,   //复位指定的虚拟机
            SuspendVM,   //挂起指定的虚拟机
            RebootVM,  //重启客户机
            ShutdownVM,  //关闭客户机
            StandbyVM,   //启动客户机操作系统待机
            s247,
            s248,
            s249,
            s250,
            s251,
            s252,
            s253,
            s254,
            s255,
            s256,
            s257,
            s258,
            s259,

            //VMSnapshot.java使用
            CreateSnapshot,  //创建虚拟机快照
            ListSnapshot,  //列举指定虚拟机的当期的全部快照
            RevertSnapshot,   //恢复到指定的快照
            RevertToCurrentSnapshot,  //恢复到当前快照
            RemoveAllSnapshot,  //删除全部快照
            RemoveSnapshot,  //移除指定的快照
            s266,
            s267,
            s268,
            s269,
            s270,
            s271,
            s272,
            s273,
            s274,
            s275,
            s276,
            s277,
            s278,
            s279,

            /****************************肖林*****************************/
            //HostRuntimeInfo.java类使用
            GetHostRuntimeInfo,//主机cpu,内存使用率
            GetHostDataStoreInfo, //主机存储器使用率
            s282,
            s283,
            s284,
            s285,
            s286,
            s287,
            s288,
            s289,
            s290,
            s291,
            s292,
            s293,
            s294,
            s295,
            s296,
            s297,
            s298,
            s299,

            //VirtualMachineRuntimeInfo.java类使用
            GetVirtualMachineCpuAndMemoryInfo, //虚拟机cpu,内存使用率
            GetVirtualMachineDiskInfo,  //虚拟机磁盘使用率
            s302,
            s303,
            s304,
            s305,
            s306,
            s307,
            s308,
            s309,
            s310,
            s311,
            s312,
            s313,
            s314,
            s315,
            s316,
            s317,
            s318,
            s319,

            //VirtualMachineReconfigure.java类使用
            VirtualMachineCpuReconfig,   //对指定主机下的虚拟机的cpu重新配置
            VirtualMachineMemoryReconfig, //对指定主机下的虚拟机的memroy重新配置
            VirtualMachineDiskReconfig,   //对指定主机下的虚拟机的指定磁盘进行重新配置
            VirtualMachineCpuHotAddAndRemoveEnable,//启用指定主机下的指定虚拟机的cpu的热插拔
            VirtualMachineMemoryHotAddEnable,//启用指定主机下的指定虚拟机的内存的热增加
            s325,
            s326,
            s327,
            s328,
            s329,
            s330,
            s331,
            s332,
            s333,
            s334,
            s335,
            s336,
            s337,
            s338,
            s339,

            //SiteFirewallDefaultPolicy.java使用
            enableFirewallDefaultPolicy,//设置主机默认开启防火墙
            undoFirewallDefaultPolicy,//设置主机默认关闭防火墙
            s341,
            s342,
            s343,
            s344,
            s345,
            s346,
            s347,
            s348,
            s349,
            s350,
            s351,
            s352,
            s353,
            s354,
            s355,
            s356,
            s357,
            s358,
            s359,


            //VNCInfo.java使用
            getVNCInfo,//VNC信息
            s361,
            s362,
            s363,
            s364,
            s365,
            s366,
            s367,
            s368,
            s369,
            s370,
            s371,
            s372,
            s373,
            s374,
            s375,
            s376,
            s377,
            s378,
            s379,
            s380,
            s381,
            s382,
            s383,
            s384,
            s385,
            s386,
            s387,
            s388,
            s389,
            s390,
            s391,
            s392,
            s393,
            s394,
            s395,
            s396,
            s397,
            s398,
            s399,
            s400,
            s401,
            s402,
            s403,
            s404,
            s405,
            s406,
            s407,
            s408,
            s409,
            s410,
            s411,
            s412,
            s413,
            s414,
            s415,
            s416,
            s417,
            s418,
            s419,
            s420,
            s421,
            s422,
            s423,
            s424,
            s425,
            s426,
            s427,
            s428,
            s429,
            s430,
            s431,
            s432,
            s433,
            s434,
            s435,
            s436,
            s437,
            s438,
            s439,
            s440,
            s441,
            s442,
            s443,
            s444,
            s445,
            s446,
            s447,
            s448,
            s449,
            s450,
            s451,
            s452,
            s453,
            s454,
            s455,
            s456,
            s457,
            s458,
            s459,
            s460,
            s461,
            s462,
            s463,
            s464,
            s465,
            s466,
            s467,
            s468,
            s469,
            s470,
            s471,
            s472,
            s473,
            s474,
            s475,
            s476,
            s477,
            s478,
            s479,
            s480,
            s481,
            s482,
            s483,
            s484,
            s485,
            s486,
            s487,
            s488,
            s489,
            s490,
            s491,
            s492,
            s493,
            s494,
            s495,
            s496,
            s497,
            s498,
            s499,
            s500

        //	s501,
        //	s502,
        //	s503,
        //	s504,
        //	s505,
        //	s506,
        //	s507,
        //	s508,
        //	s509,
        //	s510,
        //	s511,
        //	s512,
        //	s513,
        //	s514,
        //	s515,
        //	s516,
        //	s517,
        //	s518,
        //	s519,
        //	s520,
        //	s521,
        //	s522,
        //	s523,
        //	s524,
        //	s525,
        //	s526,
        //	s527,
        //	s528,
        //	s529,
        //	s530,
        //	s531,
        //	s532,
        //	s533,
        //	s534,
        //	s535,
        //	s536,
        //	s537,
        //	s538,
        //	s539,
        //	s540,
        //	s541,
        //	s542,
        //	s543,
        //	s544,
        //	s545,
        //	s546,
        //	s547,
        //	s548,
        //	s549,
        //	s550,
        //	s551,
        //	s552,
        //	s553,
        //	s554,
        //	s555,
        //	s556,
        //	s557,
        //	s558,
        //	s559,
        //	s560,
        //	s561,
        //	s562,
        //	s563,
        //	s564,
        //	s565,
        //	s566,
        //	s567,
        //	s568,
        //	s569,
        //	s570,
        //	s571,
        //	s572,
        //	s573,
        //	s574,
        //	s575,
        //	s576,
        //	s577,
        //	s578,
        //	s579,
        //	s580,
        //	s581,
        //	s582,
        //	s583,
        //	s584,
        //	s585,
        //	s586,
        //	s587,
        //	s588,
        //	s589,
        //	s590,
        //	s591,
        //	s592,
        //	s593,
        //	s594,
        //	s595,
        //	s596,
        //	s597,
        //	s598,
        //	s599,
        //	s600,
        //	s601,
        //	s602,
        //	s603,
        //	s604,
        //	s605,
        //	s606,
        //	s607,
        //	s608,
        //	s609,
        //	s610,
        //	s611,
        //	s612,
        //	s613,
        //	s614,
        //	s615,
        //	s616,
        //	s617,
        //	s618,
        //	s619,
        //	s620,
        //	s621,
        //	s622,
        //	s623,
        //	s624,
        //	s625,
        //	s626,
        //	s627,
        //	s628,
        //	s629,
        //	s630,
        //	s631,
        //	s632,
        //	s633,
        //	s634,
        //	s635,
        //	s636,
        //	s637,
        //	s638,
        //	s639,
        //	s640,
        //	s641,
        //	s642,
        //	s643,
        //	s644,
        //	s645,
        //	s646,
        //	s647,
        //	s648,
        //	s649,
        //	s650,
        //	s651,
        //	s652,
        //	s653,
        //	s654,
        //	s655,
        //	s656,
        //	s657,
        //	s658,
        //	s659,
        //	s660,
        //	s661,
        //	s662,
        //	s663,
        //	s664,
        //	s665,
        //	s666,
        //	s667,
        //	s668,
        //	s669,
        //	s670,
        //	s671,
        //	s672,
        //	s673,
        //	s674,
        //	s675,
        //	s676,
        //	s677,
        //	s678,
        //	s679,
        //	s680,
        //	s681,
        //	s682,
        //	s683,
        //	s684,
        //	s685,
        //	s686,
        //	s687,
        //	s688,
        //	s689,
        //	s690,
        //	s691,
        //	s692,
        //	s693,
        //	s694,
        //	s695,
        //	s696,
        //	s697,
        //	s698,
        //	s699,
        //	s700,
        //	s701,
        //	s702,
        //	s703,
        //	s704,
        //	s705,
        //	s706,
        //	s707,
        //	s708,
        //	s709,
        //	s710,
        //	s711,
        //	s712,
        //	s713,
        //	s714,
        //	s715,
        //	s716,
        //	s717,
        //	s718,
        //	s719,
        //	s720,
        //	s721,
        //	s722,
        //	s723,
        //	s724,
        //	s725,
        //	s726,
        //	s727,
        //	s728,
        //	s729,
        //	s730,
        //	s731,
        //	s732,
        //	s733,
        //	s734,
        //	s735,
        //	s736,
        //	s737,
        //	s738,
        //	s739,
        //	s740,
        //	s741,
        //	s742,
        //	s743,
        //	s744,
        //	s745,
        //	s746,
        //	s747,
        //	s748,
        //	s749,
        //	s750,
        //	s751,
        //	s752,
        //	s753,
        //	s754,
        //	s755,
        //	s756,
        //	s757,
        //	s758,
        //	s759,
        //	s760,
        //	s761,
        //	s762,
        //	s763,
        //	s764,
        //	s765,
        //	s766,
        //	s767,
        //	s768,
        //	s769,
        //	s770,
        //	s771,
        //	s772,
        //	s773,
        //	s774,
        //	s775,
        //	s776,
        //	s777,
        //	s778,
        //	s779,
        //	s780,
        //	s781,
        //	s782,
        //	s783,
        //	s784,
        //	s785,
        //	s786,
        //	s787,
        //	s788,
        //	s789,
        //	s790,
        //	s791,
        //	s792,
        //	s793,
        //	s794,
        //	s795,
        //	s796,
        //	s797,
        //	s798,
        //	s799,
        //	s800,
        //	s801,
        //	s802,
        //	s803,
        //	s804,
        //	s805,
        //	s806,
        //	s807,
        //	s808,
        //	s809,
        //	s810,
        //	s811,
        //	s812,
        //	s813,
        //	s814,
        //	s815,
        //	s816,
        //	s817,
        //	s818,
        //	s819,
        //	s820,
        //	s821,
        //	s822,
        //	s823,
        //	s824,
        //	s825,
        //	s826,
        //	s827,
        //	s828,
        //	s829,
        //	s830,
        //	s831,
        //	s832,
        //	s833,
        //	s834,
        //	s835,
        //	s836,
        //	s837,
        //	s838,
        //	s839,
        //	s840,
        //	s841,
        //	s842,
        //	s843,
        //	s844,
        //	s845,
        //	s846,
        //	s847,
        //	s848,
        //	s849,
        //	s850,
        //	s851,
        //	s852,
        //	s853,
        //	s854,
        //	s855,
        //	s856,
        //	s857,
        //	s858,
        //	s859,
        //	s860,
        //	s861,
        //	s862,
        //	s863,
        //	s864,
        //	s865,
        //	s866,
        //	s867,
        //	s868,
        //	s869,
        //	s870,
        //	s871,
        //	s872,
        //	s873,
        //	s874,
        //	s875,
        //	s876,
        //	s877,
        //	s878,
        //	s879,
        //	s880,
        //	s881,
        //	s882,
        //	s883,
        //	s884,
        //	s885,
        //	s886,
        //	s887,
        //	s888,
        //	s889,
        //	s890,
        //	s891,
        //	s892,
        //	s893,
        //	s894,
        //	s895,
        //	s896,
        //	s897,
        //	s898,
        //	s899,
        //	s900,
        //	s901,
        //	s902,
        //	s903,
        //	s904,
        //	s905,
        //	s906,
        //	s907,
        //	s908,
        //	s909,
        //	s910,
        //	s911,
        //	s912,
        //	s913,
        //	s914,
        //	s915,
        //	s916,
        //	s917,
        //	s918,
        //	s919,
        //	s920,
        //	s921,
        //	s922,
        //	s923,
        //	s924,
        //	s925,
        //	s926,
        //	s927,
        //	s928,
        //	s929,
        //	s930,
        //	s931,
        //	s932,
        //	s933,
        //	s934,
        //	s935,
        //	s936,
        //	s937,
        //	s938,
        //	s939,
        //	s940,
        //	s941,
        //	s942,
        //	s943,
        //	s944,
        //	s945,
        //	s946,
        //	s947,
        //	s948,
        //	s949,
        //	s950,
        //	s951,
        //	s952,
        //	s953,
        //	s954,
        //	s955,
        //	s956,
        //	s957,
        //	s958,
        //	s959,
        //	s960,
        //	s961,
        //	s962,
        //	s963,
        //	s964,
        //	s965,
        //	s966,
        //	s967,
        //	s968,
        //	s969,
        //	s970,
        //	s971,
        //	s972,
        //	s973,
        //	s974,
        //	s975,
        //	s976,
        //	s977,
        //	s978,
        //	s979,
        //	s980,
        //	s981,
        //	s982,
        //	s983,
        //	s984,
        //	s985,
        //	s986,
        //	s987,
        //	s988,
        //	s989,
        //	s990,
        //	s991,
        //	s992,
        //	s993,
        //	s994,
        //	s995,
        //	s996,
        //	s997,
        //	s998,
        //	s999,
        //	s1000,
        //	s1001,
        //	s1002,
        //	s1003,
        //	s1004,
        //	s1005,
        //	s1006,
        //	s1007,
        //	s1008,
        //	s1009,
        //	s1010,
        //	s1011,
        //	s1012,
        //	s1013,
        //	s1014,
        //	s1015,
        //	s1016,
        //	s1017,
        //	s1018,
        //	s1019,
        //	s1020,
        //	s1021,
        //	s1022,
        //	s1023,
        //	s1024,
        //	s1025,
        //	s1026,
        //	s1027,
        //	s1028,
        //	s1029,
        //	s1030,
        //	s1031,
        //	s1032,
        //	s1033,
        //	s1034,
        //	s1035,
        //	s1036,
        //	s1037,
        //	s1038,
        //	s1039,
        //	s1040,
        //	s1041,
        //	s1042,
        //	s1043,
        //	s1044,
        //	s1045,
        //	s1046,
        //	s1047,
        //	s1048,
        //	s1049,
        //	s1050,
        //	s1051,
        //	s1052,
        //	s1053,
        //	s1054,
        //	s1055,
        //	s1056,
        //	s1057,
        //	s1058,
        //	s1059,
        //	s1060,
        //	s1061,
        //	s1062,
        //	s1063,
        //	s1064,
        //	s1065,
        //	s1066,
        //	s1067,
        //	s1068,
        //	s1069,
        //	s1070,
        //	s1071,
        //	s1072,
        //	s1073,
        //	s1074,
        //	s1075,
        //	s1076,
        //	s1077,
        //	s1078,
        //	s1079,
        //	s1080,
        //	s1081,
        //	s1082,
        //	s1083,
        //	s1084,
        //	s1085,
        //	s1086,
        //	s1087,
        //	s1088,
        //	s1089,
        //	s1090,
        //	s1091,
        //	s1092,
        //	s1093,
        //	s1094,
        //	s1095,
        //	s1096,
        //	s1097,
        //	s1098,
        //	s1099,
        //	s1100,
        //	s1101,
        //	s1102,
        //	s1103,
        //	s1104,
        //	s1105,
        //	s1106,
        //	s1107,
        //	s1108,
        //	s1109,
        //	s1110,
        //	s1111,
        //	s1112,
        //	s1113,
        //	s1114,
        //	s1115,
        //	s1116,
        //	s1117,
        //	s1118,
        //	s1119,
        //	s1120,
        //	s1121,
        //	s1122,
        //	s1123,
        //	s1124,
        //	s1125,
        //	s1126,
        //	s1127,
        //	s1128,
        //	s1129,
        //	s1130,
        //	s1131,
        //	s1132,
        //	s1133,
        //	s1134,
        //	s1135,
        //	s1136,
        //	s1137,
        //	s1138,
        //	s1139,
        //	s1140,
        //	s1141,
        //	s1142,
        //	s1143,
        //	s1144,
        //	s1145,
        //	s1146,
        //	s1147,
        //	s1148,
        //	s1149,
        //	s1150,
        //	s1151,
        //	s1152,
        //	s1153,
        //	s1154,
        //	s1155,
        //	s1156,
        //	s1157,
        //	s1158,
        //	s1159,
        //	s1160,
        //	s1161,
        //	s1162,
        //	s1163,
        //	s1164,
        //	s1165,
        //	s1166,
        //	s1167,
        //	s1168,
        //	s1169,
        //	s1170,
        //	s1171,
        //	s1172,
        //	s1173,
        //	s1174,
        //	s1175,
        //	s1176,
        //	s1177,
        //	s1178,
        //	s1179,
        //	s1180,
        //	s1181,
        //	s1182,
        //	s1183,
        //	s1184,
        //	s1185,
        //	s1186,
        //	s1187,
        //	s1188,
        //	s1189,
        //	s1190,
        //	s1191,
        //	s1192,
        //	s1193,
        //	s1194,
        //	s1195,
        //	s1196,
        //	s1197,
        //	s1198,
        //	s1199,
        //	s1200,
        //	s1201,
        //	s1202,
        //	s1203,
        //	s1204,
        //	s1205,
        //	s1206,
        //	s1207,
        //	s1208,
        //	s1209,
        //	s1210,
        //	s1211,
        //	s1212,
        //	s1213,
        //	s1214,
        //	s1215,
        //	s1216,
        //	s1217,
        //	s1218,
        //	s1219,
        //	s1220,
        //	s1221,
        //	s1222,
        //	s1223,
        //	s1224,
        //	s1225,
        //	s1226,
        //	s1227,
        //	s1228,
        //	s1229,
        //	s1230,
        //	s1231,
        //	s1232,
        //	s1233,
        //	s1234,
        //	s1235,
        //	s1236,
        //	s1237,
        //	s1238,
        //	s1239,
        //	s1240,
        //	s1241,
        //	s1242,
        //	s1243,
        //	s1244,
        //	s1245,
        //	s1246,
        //	s1247,
        //	s1248,
        //	s1249,
        //	s1250,
        //	s1251,
        //	s1252,
        //	s1253,
        //	s1254,
        //	s1255,
        //	s1256,
        //	s1257,
        //	s1258,
        //	s1259,
        //	s1260,
        //	s1261,
        //	s1262,
        //	s1263,
        //	s1264,
        //	s1265,
        //	s1266,
        //	s1267,
        //	s1268,
        //	s1269,
        //	s1270,
        //	s1271,
        //	s1272,
        //	s1273,
        //	s1274,
        //	s1275,
        //	s1276,
        //	s1277,
        //	s1278,
        //	s1279,
        //	s1280,
        //	s1281,
        //	s1282,
        //	s1283,
        //	s1284,
        //	s1285,
        //	s1286,
        //	s1287,
        //	s1288,
        //	s1289,
        //	s1290,
        //	s1291,
        //	s1292,
        //	s1293,
        //	s1294,
        //	s1295,
        //	s1296,
        //	s1297,
        //	s1298,
        //	s1299,
        //	s1300,
        //	s1301,
        //	s1302,
        //	s1303,
        //	s1304,
        //	s1305,
        //	s1306,
        //	s1307,
        //	s1308,
        //	s1309,
        //	s1310,
        //	s1311,
        //	s1312,
        //	s1313,
        //	s1314,
        //	s1315,
        //	s1316,
        //	s1317,
        //	s1318,
        //	s1319,
        //	s1320,
        //	s1321,
        //	s1322,
        //	s1323,
        //	s1324,
        //	s1325,
        //	s1326,
        //	s1327,
        //	s1328,
        //	s1329,
        //	s1330,
        //	s1331,
        //	s1332,
        //	s1333,
        //	s1334,
        //	s1335,
        //	s1336,
        //	s1337,
        //	s1338,
        //	s1339,
        //	s1340,
        //	s1341,
        //	s1342,
        //	s1343,
        //	s1344,
        //	s1345,
        //	s1346,
        //	s1347,
        //	s1348,
        //	s1349,
        //	s1350,
        //	s1351,
        //	s1352,
        //	s1353,
        //	s1354,
        //	s1355,
        //	s1356,
        //	s1357,
        //	s1358,
        //	s1359,
        //	s1360,
        //	s1361,
        //	s1362,
        //	s1363,
        //	s1364,
        //	s1365,
        //	s1366,
        //	s1367,
        //	s1368,
        //	s1369,
        //	s1370,
        //	s1371,
        //	s1372,
        //	s1373,
        //	s1374,
        //	s1375,
        //	s1376,
        //	s1377,
        //	s1378,
        //	s1379,
        //	s1380,
        //	s1381,
        //	s1382,
        //	s1383,
        //	s1384,
        //	s1385,
        //	s1386,
        //	s1387,
        //	s1388,
        //	s1389,
        //	s1390,
        //	s1391,
        //	s1392,
        //	s1393,
        //	s1394,
        //	s1395,
        //	s1396,
        //	s1397,
        //	s1398,
        //	s1399,
        //	s1400,
        //	s1401,
        //	s1402,
        //	s1403,
        //	s1404,
        //	s1405,
        //	s1406,
        //	s1407,
        //	s1408,
        //	s1409,
        //	s1410,
        //	s1411,
        //	s1412,
        //	s1413,
        //	s1414,
        //	s1415,
        //	s1416,
        //	s1417,
        //	s1418,
        //	s1419,
        //	s1420,
        //	s1421,
        //	s1422,
        //	s1423,
        //	s1424,
        //	s1425,
        //	s1426,
        //	s1427,
        //	s1428,
        //	s1429,
        //	s1430,
        //	s1431,
        //	s1432,
        //	s1433,
        //	s1434,
        //	s1435,
        //	s1436,
        //	s1437,
        //	s1438,
        //	s1439,
        //	s1440,
        //	s1441,
        //	s1442,
        //	s1443,
        //	s1444,
        //	s1445,
        //	s1446,
        //	s1447,
        //	s1448,
        //	s1449,
        //	s1450,
        //	s1451,
        //	s1452,
        //	s1453,
        //	s1454,
        //	s1455,
        //	s1456,
        //	s1457,
        //	s1458,
        //	s1459,
        //	s1460,
        //	s1461,
        //	s1462,
        //	s1463,
        //	s1464,
        //	s1465,
        //	s1466,
        //	s1467,
        //	s1468,
        //	s1469,
        //	s1470,
        //	s1471,
        //	s1472,
        //	s1473,
        //	s1474,
        //	s1475,
        //	s1476,
        //	s1477,
        //	s1478,
        //	s1479,
        //	s1480,
        //	s1481,
        //	s1482,
        //	s1483,
        //	s1484,
        //	s1485,
        //	s1486,
        //	s1487,
        //	s1488,
        //	s1489,
        //	s1490,
        //	s1491,
        //	s1492,
        //	s1493,
        //	s1494,
        //	s1495,
        //	s1496,
        //	s1497,
        //	s1498,
        //	s1499,
        //	s1500
      };
};
#endif // MESSAGETYPE_H