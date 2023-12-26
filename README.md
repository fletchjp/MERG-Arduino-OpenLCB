# MERG-Arduino-OpenLCB
 Arduino codes using OpenLCB
 
 I am going to build my own examples using the OpenLCB_Single_Thread library.
 
 I have added DUE capability to that which is as yet untested. This needs to have an external EEPROM option added.
 
 I am going to develop my own example uses here.
 
 I have copied two of the examples to work on here.
 
 John Fletcher \<M6777\> john@bunbury28.plus.com
 
 ## OlcbBlankNode
 
 A copy of the blank example from the OpenLCB_Single_Thread library.
 
 ## OlcbBasicNode
 
 A copy of the basic example from the OpenLCB_Single_Thread library.
 
 ## OlcbBridgeNode
 
 This is intended to be a bridge node supporting both OpenLCB and CBUS using an Arduino DUE with two CAN ports.
 
 This involves a number of design choices which have yet to be sorted out.
 
 One is to decide which CAN port to use for which bus system. It may be easier to have OpenLCB on CAN0 and CBUS on CAN1.
 
 The other is to sort out a structure for the use of EEPROM so that the data for the two buses does not overlap.
 
 There is a problem to be resolved for use of external EEPROM in that both buses need access. Only one initiation of the I2C is needed.
 
 
