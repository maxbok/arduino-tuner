#ifdef __cplusplus
extern "C" {
#endif


#define NULL 0

// pin 4 => ST_CP
#define SSD_LATCH_DDR  DDRD
#define SSD_LATCH_PORT PORTD
#define SSD_LATCH_BIT  4
// pin 5 => SH_CP
#define SSD_CLOCK_DDR  DDRD
#define SSD_CLOCK_PORT PORTD
#define SSD_CLOCK_BIT  5
// pin 6 => DS
#define SSD_DATA_DDR   DDRD
#define SSD_DATA_PORT  PORTD
#define SSD_DATA_BIT   6


#ifdef __cplusplus
}
#endif

