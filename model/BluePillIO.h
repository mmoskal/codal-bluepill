/*
The MIT License (MIT)

Copyright (c) 2017 Lancaster University.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef BIG_BluePill_IO_H
#define BIG_BluePill_IO_H

#include "CodalConfig.h"
#include "ZPin.h"

//
// Unique Pin number for each pin (synonymous with mbedos PinName)
//


//
// Component IDs for each pin.
// The can be user defined, but uniquely identify a pin when using the eventing APIs/
//
#define ID_PIN_PA0           (DEVICE_ID_IO_P0 + 0)
#define ID_PIN_PB0           (DEVICE_ID_IO_P0 + 16)
#define ID_PIN_PC0           (DEVICE_ID_IO_P0 + 32)

namespace codal
{
    /**
     * Represents a collection of all I/O pins exposed by the device.
     */
    class BluePillIO
    {
        public:
            ZPin pa[0];
            ZPin pa0;
            ZPin pa1;
            ZPin pa2;
            ZPin pa3;
            ZPin pa4;
            ZPin pa5;
            ZPin pa6;
            ZPin pa7;
            ZPin pa8;
            ZPin pa9;
            ZPin pa10;
            ZPin pa11;
            ZPin pa12;
            ZPin pa13;
            ZPin pa14;
            ZPin pa15;
            ZPin pb[0];
            ZPin pb0;
            ZPin pb1;
            ZPin pb2;
            ZPin pb3;
            ZPin pb4;
            ZPin pb5;
            ZPin pb6;
            ZPin pb7;
            ZPin pb8;
            ZPin pb9;
            ZPin pb10;
            ZPin pb11;
            ZPin pb12;
            ZPin pb13;
            ZPin pb14;
            ZPin pb15;

            ZPin led;

            /**
             * Constructor.
             */
            BluePillIO();
    };
}

#endif
