# OlcbBlankNode

This is a minimal sketch that can be expanded for applications.  

It has no user CDI defined, nor memStruct, but does demonstrate that there is are minimal fields for nodeName and nodeDesc, 
which are standard practice.  

It has empty definitions for **buttons[]**, **pceCallback(unsigned int index)**, **produceFromInputs()**, **userInitAll()**, 
and **userConfigWritten()**, etc. 

Other more developed sketches may be easier to modify.

## Modification

This copy has extra output to document its use.

I have added output to the DebugStream and I am using the code compiled for an Arduino UNO to find out more about how it works.

This code is now running using the simulated EEPROM available with the Arduino DUE.

As the DUE has two CAN ports the user code has to chose which one to use. This is done with calls to setControllerInstance. Without these two calls the code does not work.
