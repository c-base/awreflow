/*
 * Andy's Workshop Reflow Oven Controller.
 * Copyright (c) 2014 Andy Brown. All rights reserved.
 * Please see website (http://www.andybrown.me.uk) for full details.
 */

#include "Application.h"


namespace awreflow {


  /*
   * Show the splash screen and hold for 5 seconds
   */

  void SplashScreen::show(Panel& panel) {

    FlashGraphics flash(panel);

    // lights off (this is an async fade)

    panel.setBacklight(0);
    MillisecondTimer::delay(1000);

   // draw the "reflow" graphic (full screen)

    flash.drawBitmap(
        Rectangle(0,0,FlashInfo::LOGO640X360::WIDTH,FlashInfo::LOGO640X360::HEIGHT),
        FlashInfo::LOGO640X360::OFFSET,
        FlashInfo::LOGO640X360::LENGTH);

    // lights on and hold

    panel.setBacklight(100);
    MillisecondTimer::delay(DISPLAY_HOLD_MILLIS);
  }
}
