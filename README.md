# Underwater-acoustic-communication
Demonstrated working of underwater acoustic communication of range within 5cm to 8cm with lm386 on tx side and lm358 on rx side with fsk encoding technique using Arduino Uno 
## system architecture
Arduino (TX) → LM386 power amp → Piezo TX → Water → Piezo RX → AC coupling → LM358 op-amp → Arduino (RX)
FSK encoding: 4 kHz = bit 0, 5 kHz = bit 1
## Hardware setup
Two piezo discs in a water-filled glass jar (TX + RX)
Breadboard circuits, single 9V battery, shared/star ground
Decoupling capacitor to isolate TX noise from RX
<img width="963" height="1280" alt="image" src="https://github.com/user-attachments/assets/2c52b1c2-6c9c-4a74-b0b9-1b15cab9e12a" />
## Circuit design
TX: Arduino → coupling cap → LM386 (gain ~200) → 92µF output cap → piezo
RX: Piezo → 1µF AC coupling → LM358 (2.5V bias, gain ~17.5) → Arduino A0
<img width="1600" height="1540" alt="image" src="https://github.com/user-attachments/assets/7486bce0-0e67-410a-bce7-65084df977de" />
<img width="1600" height="1195" alt="image" src="https://github.com/user-attachments/assets/4a1fee07-9d50-4b21-a2a6-141546ee9981" />
## Results
No TX: ADC flat, ~512–516 (baseline noise)
TX active: ADC varies, ~506–518
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/3018cbb9-363c-4d3c-9305-78928fca692b" />
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/4646a945-ae23-4433-afc0-884b5c486870" />
## honest limitations
FSK proof is informal (energy levels, not FFT — FFT run but not saved)
Very short range, tested only in a jar
No real bit/byte decoding, just signal-present detection
Low-cost piezo discs, not proper underwater transducers
Analog heuristic detection, not matched filter/digital



