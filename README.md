# fishykeeb

FishyKeeb is a sting-ray shaped compact 4X1 customizable macroboard. It is made for Sunbeam Delhi! It is powered by a XIAORP2040. Uses Cherry MX Red Switches. 

---

<img width="420" height="595" alt="ZINE" src="https://github.com/user-attachments/assets/8d4c9b09-00aa-4add-a0a9-179deeb2c5dd" />

<br>



## How it works

- Plug the XIAO into your computer and upload firmware through the Arduino IDE given in this repository or use the QMK Firmware (https://qmk.fm/)
- The macropad is now ready to use! (pretty simple init)

  <br>
<img width="726" height="733" alt="image" src="https://github.com/user-attachments/assets/256a6950-ad7e-49bb-96b3-baddba123f0c" />


<br>

## Why Fishy Keeb was made?

Fishy Keeb is made to be given out as a prize to winners in Sunbeam Delhi. It is a very cool-looking macro-pad which you can customize to do anything you'd like!

<br>

## Schematic
<img width="455" height="328" alt="image" src="https://github.com/user-attachments/assets/7b978e37-e87d-42dd-9bce-f558dcfc19cd" />


<br>


## PCB
<img width="503" height="337" alt="image" src="https://github.com/user-attachments/assets/49e0d6b1-bf57-452b-abd7-2b6c3bb68344" />


<br>
<img width="1113" height="652" alt="image" src="https://github.com/user-attachments/assets/e8973100-9581-431e-98bf-562ca79a63f8" />


<br>

## The Case
<img width="773" height="706" alt="image" src="https://github.com/user-attachments/assets/7b2bc5c2-3be1-4859-8553-e8e77f23f8bc" />
<br>

<img width="844" height="712" alt="image" src="https://github.com/user-attachments/assets/a4e82900-c1fb-4780-b197-9769bfc50ceb" />

## Fusion Files: https://a360.co/4wC0P4i

<br>

## How to Build

1. Download the KiCad files and then generate gerber files. <br>
2. go to jlcpcb.com and place the order for the pcb!
3. Buy all components listed in the BOM. <br>
4. On receiving your PCB, solder the XIAO and the MX Cherry switches to the PCB.
5. Place the keycaps on the switches.
6. Use the CAD files given in the repo to 3D-print the top and bottom case of the fishy keeb.
7. Place the assembled PCB in the bottom case and close it by aligning the top case.
8. Use M3 Screws to hold the two parts of the cases together in place.
9. Connect the XIAO to your computer and flash it with the firmware (either the .ino file using Arduino IDE or by using qmk.fm).
10. Your fishy keeb is ready to use!!


## Bill of Materials (BOM)

| S.No. | Reference | Value | Product Name | Note | Qty | Cost (INR) | Link |
|-------|-----------|-------|---------------|------|-----|-------------|------|
| 1 | U1 | XIAO-RP2040-DIP | XIAO RP2040 | on the pcb | 1 | 529 | [Link](https://robu.in/product/seeed-studio-xiao-rp2040-v1-0/) |
| 2 | SW1, SW2, SW3, SW4 | SW_Push | Cherry MX Switches | on the pcb | 4 | 488 | [Link](https://www.mouser.in/en/ProductDetail/CHERRY/MX2A-E1NB) |
| 3 | — | — | PCB | the pcb | 1 | 190 | [Link](https://cart.jlcpcb.com/quote) |
| 4 | — | — | Bottom Case | 3D printed | 1 | 408 | [Link](https://zbotic.in/product/online-3d-printing-service/) |
| 5 | — | — | Top Case | 3D printed | 1 | 257 | [Link](https://zbotic.in/product/online-3d-printing-service/) |
| 6 | — | — | Screws | just screws | 4 | 6 | [Link](https://onlyscrews.in/products/phillips-csk-m3-x-10mm-pack-of-20) |
| 7 | — | — | Key Caps | just keycaps | 4 | 32 | [Link](https://rajivelectronics.com/product/cherry-mx-compatible-transparent-keycap-mechanical-keyboard-keycap) |

**Total estimated cost:** ₹1910








