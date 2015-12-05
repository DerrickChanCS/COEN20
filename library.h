#define	HEADER		"SCU COEN 20"
#define	ERROR_FLAG	"ERR"

void InitializeHardware(char *header, char *footer) ;
void WaitForPushButton(void) ;
uint8_t PrintBits(int bin[]) ;
void PrintByte(uint8_t byte) ;
void ClearDisplay(void) ;
uint32_t GetClockCycleCount(void) ;
