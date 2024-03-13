# MERG-Arduino-OpenLCB
 Arduino codes using OpenLCB
 
 I am going to build my own examples using the OpenLCB_Single_Thread library.
 
 I have added DUE capability to that which is as yet untested. This needs to have an external EEPROM option added.
 
 I am going to develop my own example uses here.
 
 I have copied two of the examples to work on here.
 
 John Fletcher \<M6777\> john@bunbury28.plus.com
 
 ## OpenLCB_Single_Thread library
 
 I now have a fork of this library which is where I am assembling the changes I am making to the library.
 
 There is also a working copy in the Arduino/libraries folder which is the one used when the examples are compiled.

 ### DUE implementation
 
 I have now sorted out various errors with the DUE implementation which is now working on the BlankNode example.

 ### EEPROM on the DUE
 
 Central to the plans is the need to support configuration on the Arduino DUE. There are two ways to do this, using the DueFlashStorage library and using an external EEPROM.
 
 I have adapted code to work with the DueFlashStorage library which is now working. I have done some tests to develop my implementation.
 
 ### ESP32 implementation
 
 I have made some changes to this to get the EEPROM code working.
 
 ### RP2040 implementation
 
 David Harris says that this is work in progress.
 
 ## Examples
 
 ### OlcbBlankNode
 
 A copy of the blank example from the OpenLCB_Single_Thread library. This now runs with an Arduino DUE.
 
 ### OlcbBasicNode
 
 A copy of the basic example from the OpenLCB_Single_Thread library. Modifications started to run with Arduino DUE.
 
 ### OlcbBridgeNode
 
 This is an intention which has not yet been started.
 
 This is intended to be a bridge node supporting both OpenLCB and CBUS using an Arduino DUE with two CAN ports.
 
 This involves a number of design choices which have yet to be sorted out.
 
 One is to decide which CAN port to use for which bus system. It may be easier to have OpenLCB on CAN0 and CBUS on CAN1.
 
 The other is to sort out a structure for the use of EEPROM so that the data for the two buses does not overlap.
 
 There is a problem to be resolved for use of external EEPROM in that both buses need access. Only one initiation of the I2C is needed. One solution could be to use the CBUS configuration library for all cases.
 
