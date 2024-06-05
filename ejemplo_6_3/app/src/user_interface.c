/********************** inclusions *******************************************/

#include "user_interface.h"
#include "display.h"
#include <string.h>

/********************** macros and definitions *******************************/
#define DISPLAY_REFRESH_TIME_MS  1000
#define SYSTEM_TIME_INCREMENT_MS 10
/********************** internal data declaration ****************************/
/********************** internal functions declaration ***********************/
static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
/********************** internal data definition *****************************/
/********************** external data declaration ****************************/
/********************** external functions definition ************************/
void userInterfaceInit()
{

    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{

    userInterfaceDisplayUpdate();
}
/********************** internal functions definition ************************/
static void userInterfaceDisplayInit()
{
    //displayInit( DISPLAY_CONNECTION_GPIO_8BITS );
    displayInit( DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER );
    //displayInit( DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER );
    displayCharPositionWrite ( 0,0 );
	displayStringWrite( "Temperature:" );

	displayCharPositionWrite ( 0,1 );
	displayStringWrite( "Gas:" );

	displayCharPositionWrite ( 0,2 );
	displayStringWrite( "Alarm:" );

}

static void userInterfaceDisplayUpdate()
{
	static int accumulatedDisplayTime = 0;
	char temperatureString[3] = "19";

	if( accumulatedDisplayTime >=
		DISPLAY_REFRESH_TIME_MS ) {

		accumulatedDisplayTime = 0;


		displayCharPositionWrite ( 12,0 );
		displayStringWrite( temperatureString );
		displayCharPositionWrite ( 14,0 );
		displayStringWrite( "'C" );

	} else {
		accumulatedDisplayTime =
			accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;
	}
}
/********************** end of file ******************************************/


