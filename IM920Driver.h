#ifndef LIB_IM920_HEADER_FILE
#define LIB_IM920_HEADER_FILE

#include <SoftwareSerial.h>
#include "Arduino.h"

// length of buffer
#define IM920_BUFFER_SIZE 80

class IM920Driver {
  public:
    // constructor
    IM920Driver(SoftwareSerial *ser);
    // read 1 character
    char read();
    // return true if buffer contains data
    bool available();
    // send string data to im920 with "\r\n"
    void send(const char str[]) ;
    // get last line data
    void get_last_line(char buff[IM920_BUFFER_SIZE]);
    // get the length of line data
    int16_t get_line_length();
    // true if new line received
    bool get_line_changed();

  private:

    SoftwareSerial *_ser;             // Serial which connected to IM920
    uint8_t *_current_line;           // reading line
    uint8_t *_last_line;              // last line
    uint8_t _line1[IM920_BUFFER_SIZE];// buffer of line data 1
    uint8_t _line2[IM920_BUFFER_SIZE];// buffer of line data 1
    uint16_t _idx;                    // length of _current_line
    uint16_t _line_length;            // length of _last_line
    bool _line_changed;               // true if line changed
};

#endif

