#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>

#include <vpad/input.h>

int main(int argc, char **argv)
{
   WHBProcInit();
   WHBLogConsoleInit();

   while(WHBProcIsRunning()) {
      VPADStatus vpad;
      VPADRead(0, &vpad, 1, NULL);

      if (vpad.trigger == VPAD_BUTTON_PLUS){
         break; // When user presses the + button on the controller or gamepad, the application will close. 
      }

      WHBLogConsoleDraw();
   }

   WHBLogPrintf("Exiting... good bye.");
   WHBLogConsoleDraw();
   OSSleepTicks(OSMillisecondsToTicks(1000));

   WHBLogConsoleFree();
   WHBProcShutdown();
   return 0;
}
