# About

This repository contains code for my Remote Lamp Switch based on the ESP8266 microcontroller. 

My parents had a hard-accessible lamp in their living room and wanted to control it remotely. Instead of buying a remote-controlled lamp, or even a remote controlled relay, I accepted the challenge of building it myself. 

# Warning ⚠️

⚠️ This project deals with mains circuitry, which can be lethal if not careful, so do not attempt to recreate this project, unless you know exactly what you are doing!!

# Build

<div align="center">
  <img src="https://github.com/user-attachments/assets/3fbbf994-244e-44cb-b9c6-a2f9d0f06820" alt="Schematic" height="260"/>
</div>

## Main Components

- ESP8266-12E - WiFi Communication
- 220V AC-DC 5V Converter - Main Power Supply (There also exists a direct 3.3V converter, but I had the 5V one lying around.)
- AMS1117 3.3V - Power Supply for ESP
- MOC3041M - Optocoupler Triac Driver
- BTA16-800 - Triac (Solid State Relay)
- 2x KF301 - Screwed Wire Terminals for the AC Wires

## Board

The components are all soldered onto a custom PCB together with some resistors, leds, capacitors, headers and buttons. To minimize chance of an accident, the mains part of the board is separated from the low voltage size as much as possible. 
The only two components bridging the gap between AC and DC are the voltage converter and the optocoupler.

<div align="center">
  <img src="https://github.com/user-attachments/assets/afd91c83-1687-4dfa-aa3d-c7456e7fbf85" alt="Board" height="240"/>
  <img src="https://github.com/user-attachments/assets/edda382a-56f0-4928-91a8-93b6f38a3b27" alt="BoardFront" height="240">
</div>

## Box

The board is then screwed into a 3D printed box that I designed. The box has some air vents on the top and bottom to allow passive cooling of the electronics. These are designed, so that nothing can get through them, but air! The button on the top is a manual switch, in case the network is down.

<div align="center">
  <img src="https://github.com/user-attachments/assets/1a56fb5e-ea99-4bf3-a278-21ba52242884" alt="BoardBox" height="300"/>
  <img src="https://github.com/user-attachments/assets/ccc4f81d-7c17-4150-8732-111b13d0cd6b" alt="Box" height="300">
</div>

## Mains wires  

The mains wires are secured using screw terminals and are further supported by friction within the tight-tolerance holes in the enclosure. Since the box is lightweight, it is suspended directly from the wires, as shown in the image below.

Initially, I considered gluing the wires in place for added security, but this proved unnecessary—the wires are held firmly as-is. Additionally, the lamp is installed in a hard-to-reach area where it’s unlikely to be disturbed.

As a safety measure, I periodically check the integrity of the wire connections and retighten the terminals if needed.

<div align="center">
  <img src="https://github.com/user-attachments/assets/56dd3448-8fb3-44f5-9d11-10a8e4218d4c" alt="Schematic" height="400"/>
</div>

And at last, here is my mom controlling the lamp with a simple android app I made for her (Just two buttons sending an HTTP GET request to the lamp IP address).

<div align="center">
  <img src="https://github.com/user-attachments/assets/619e9130-f378-42ff-8d7d-87e09c5614c8" alt="Schematic" height="260"/>
</div>

# Disclaimer

The information, code, and schematics provided in this project are for educational purposes only. By using or replicating this project, you acknowledge that you are responsible for ensuring compliance with all local laws and regulations, including wireless communication standards and electrical safety protocols. The author takes no responsibility for any damage, injury, or legal consequences arising from the use or misuse of this project. Use this project at your own risk.
