/*
 * Andy's Workshop Reflow Oven Controller.
 * Copyright (c) 2014 Andy Brown. All rights reserved.
 * Please see website (http://www.andybrown.me.uk) for full details.
 */

#pragma once


namespace awreflow {


  /*
   * The options page manages the selection of the profile and the
   * customisation of the PID parameters.
   */

  class ControlPage : public PageBase {

    protected:
      enum {
        LEADED       = 0,
        LEAD_FREE    = 1,
        REFLOW       = 2,
        PROPORTIONAL = 4,
        INTEGER      = 5,
        DERIVATIVE   = 6
      } _selectedButton;

      bool _leadedChecked;
      bool _captive;
      TemperatureControlWriter _temperature;
      BlueIntegerWriter _p;
      BlueIntegerWriter _i;
      BlueIntegerWriter _d;

    protected:
      void redrawAll();
      void drawSelectionAndCheck(Flash& flash,bool draw);
      void drawSelection(bool draw) const;
      void drawCheck(Flash& flash) const;
      void drawCheck(Flash& flash,uint8_t selbtn,uint32_t offset,uint32_t length,Panel::tCOLOUR colour,uint8_t deselbtn) const;
      void handleRight();
      void handleLeft();
      bool handleOk();

    public:
      ControlPage(Panel& panel,Buttons& buttons);

      ReflowParameters run();
  };


  /*
   * Constructor
   */

  inline ControlPage::ControlPage(Panel& panel,Buttons& buttons)
    : PageBase(panel,buttons),
      _selectedButton(REFLOW),
      _leadedChecked(true),
      _captive(false),
      _p(1,0,999,Point(500,85)),
      _i(1,0,999,Point(500,182)),
      _d(1,0,999,Point(500,280)) {
  }
}