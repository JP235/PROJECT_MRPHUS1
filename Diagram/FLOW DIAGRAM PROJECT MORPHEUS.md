# FLOW DIAGRAM PROJECT MORPHEUS

1. Battery (rechargeable trough microUSB) —> on/off switch
2. MICROPHONE ANALOG INPUT —> SAVE DATA CSV, DETECT SNORE
3. RTC —> TIME STAMP FOR DATA (SOUND AND EOG) (save CSV)
4. BLUETOOTH —> TWO MODES:
   1. REALTIME COMUNICATION AND DATA TRANSFER (CONTROL)
   2. DATA TRANSFER AFTER SLEEP
5. MYOWARE —> EOG (save CSV), detect REM
6. ARDUINO MKZERO —>2 MODES:
   1. RECORD MODE —>( ANALYZE DATA NOT WAKE UP IF REM ALGORITHM)
   2. LIVE AND RECORD MODE "" 