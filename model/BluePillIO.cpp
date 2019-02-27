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

/**
 * Class definition for MicroBit NEXT IO.
 * Represents a collection of all I/O pins on the device.
 */

#include "CodalConfig.h"
#include "BluePillIO.h"

using namespace codal;

/**
 * Constructor.
 *
 * Create a representation of all given I/O pins on the edge connector
 *
 * Accepts a sequence of unique ID's used to distinguish events raised
 * by MicroBitPin instances on the default EventModel.
 */
BluePillIO::BluePillIO()
    : pa0(ID_PIN_PA0 + 0, PA_0, PIN_CAPABILITY_DIGITAL),
      pa1(ID_PIN_PA0 + 1, PA_1, PIN_CAPABILITY_DIGITAL),
      pa2(ID_PIN_PA0 + 2, PA_2, PIN_CAPABILITY_DIGITAL),
      pa3(ID_PIN_PA0 + 3, PA_3, PIN_CAPABILITY_DIGITAL),
      pa4(ID_PIN_PA0 + 4, PA_4, PIN_CAPABILITY_DIGITAL),
      pa5(ID_PIN_PA0 + 5, PA_5, PIN_CAPABILITY_DIGITAL),
      pa6(ID_PIN_PA0 + 6, PA_6, PIN_CAPABILITY_DIGITAL),
      pa7(ID_PIN_PA0 + 7, PA_7, PIN_CAPABILITY_DIGITAL),
      pa8(ID_PIN_PA0 + 8, PA_8, PIN_CAPABILITY_DIGITAL),
      pa9(ID_PIN_PA0 + 9, PA_9, PIN_CAPABILITY_DIGITAL),
      pa10(ID_PIN_PA0 + 10, PA_10, PIN_CAPABILITY_DIGITAL),
      pa11(ID_PIN_PA0 + 11, PA_11, PIN_CAPABILITY_DIGITAL),
      pa12(ID_PIN_PA0 + 12, PA_12, PIN_CAPABILITY_DIGITAL),
      pa13(ID_PIN_PA0 + 13, PA_13, PIN_CAPABILITY_DIGITAL),
      pa14(ID_PIN_PA0 + 14, PA_14, PIN_CAPABILITY_DIGITAL),
      pa15(ID_PIN_PA0 + 15, PA_15, PIN_CAPABILITY_DIGITAL),
      pb0(ID_PIN_PB0 + 0, PB_0, PIN_CAPABILITY_DIGITAL),
      pb1(ID_PIN_PB0 + 1, PB_1, PIN_CAPABILITY_DIGITAL),
      pb2(ID_PIN_PB0 + 2, PB_2, PIN_CAPABILITY_DIGITAL),
      pb3(ID_PIN_PB0 + 3, PB_3, PIN_CAPABILITY_DIGITAL),
      pb4(ID_PIN_PB0 + 4, PB_4, PIN_CAPABILITY_DIGITAL),
      pb5(ID_PIN_PB0 + 5, PB_5, PIN_CAPABILITY_DIGITAL),
      pb6(ID_PIN_PB0 + 6, PB_6, PIN_CAPABILITY_DIGITAL),
      pb7(ID_PIN_PB0 + 7, PB_7, PIN_CAPABILITY_DIGITAL),
      pb8(ID_PIN_PB0 + 8, PB_8, PIN_CAPABILITY_DIGITAL),
      pb9(ID_PIN_PB0 + 9, PB_9, PIN_CAPABILITY_DIGITAL),
      pb10(ID_PIN_PB0 + 10, PB_10, PIN_CAPABILITY_DIGITAL),
      pb11(ID_PIN_PB0 + 11, PB_11, PIN_CAPABILITY_DIGITAL),
      pb12(ID_PIN_PB0 + 12, PB_12, PIN_CAPABILITY_DIGITAL),
      pb13(ID_PIN_PB0 + 13, PB_13, PIN_CAPABILITY_DIGITAL),
      pb14(ID_PIN_PB0 + 14, PB_14, PIN_CAPABILITY_DIGITAL),
      pb15(ID_PIN_PB0 + 15, PB_15, PIN_CAPABILITY_DIGITAL),
      led(ID_PIN_PC0 + 13, PC_13, PIN_CAPABILITY_DIGITAL)

{
}
