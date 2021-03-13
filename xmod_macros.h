#define BIT(x) (1 << x)

//Xmod arguments
#define MAX_ARGS 6
#define MIN_ARGS 3

//Users masks
#define USER_MASK 0x3F
#define GROUP_MASK 0x1C7
#define OTHERS_MASK 0x1F8
#define ALL_MASK 0x1FF

//Read, Write and Execute Bits 
#define R_BIT BIT(2)
#define W_BIT BIT(1)
#define X_BIT BIT(0)

//Options
#define NO_OPTION 0x0
#define C_OPTION_MASK BIT(1)
#define V_OPTION_MASK (BIT(2) | BIT(0))
#define R_OPTION_MASK BIT(0)  
#define VC_OPTION_MASK BIT(2)
#define V_OPTION 2 
#define C_OPTION 3
