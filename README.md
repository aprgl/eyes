# eyes
Simple ESP32 based eyes using a smart watch display

https://github.com/user-attachments/assets/1ac2642b-cd37-4aac-a159-ac74730e4304

[High res version of the demo video](https://www.youtube.com/watch?v=qhqZ3XsuadY)

The crow head was a clay sculpture by @null-object1 for making masks with, then I made some eyes for it!

<img width="424" height="331" alt="image" src="https://github.com/user-attachments/assets/5b6f12b1-29a7-4a69-a6ca-5bac75727f06" />

# Electronic Parts
Watch display - 1.28 Inch TFT LCD Display Module Round RGB 240 * 240 GC9A01 Driver 4 Wire SPI Interface 240x240 purchased in a three pack from amazon for ~ $17 - [Link](https://a.co/d/3S3zLky)

<img width="424" height="331" alt="image" src="https://github.com/user-attachments/assets/f1bed522-794f-4b34-b316-dd7e950ff673" />

ESP32  - Little ESP32 dev board. I used [these](https://a.co/d/7bbREvP) because I had them lying around but any esp32 would work. five pack for $30

<img width="424" height="331" alt="image" src="https://github.com/user-attachments/assets/a6cc1ca6-3488-4610-8b19-36ec40d79d19" />

# Casting Supplies
Half sphere silicone cake mold - [I used these ones](https://a.co/d/4Kx03Kw) $15 

<img width="424" height="331" alt="image" src="https://github.com/user-attachments/assets/6a108137-4680-46b2-bac2-436bbe1295bb" />

Crystal Clear Epoxy - I tried different epoxy first but I think temperature in the garage was too low so I couldn't degass it without boiling over, [this stuff was much thinner and degassed without issue](https://a.co/d/6fECwrN). ~$20

<img width="400" alt="image" src="https://github.com/user-attachments/assets/f7af370a-0254-4958-86b7-223c061dcdc8" />

# Procedure
1. Laser cut (or ask a friend, or order on pololu or similar) backstop.svg. This is the 
2. Cutout a black (or whatever color preference) sticker using a vinyl cutter and the sticker.svg file, or scissors with a 2.5in OD and 1.28in ID
3. Apply the sticker to the laser cut backstop concentric to the outer edge
4. Place the display in the backstop using the sticker to lock it in place

<img width="400" alt="image" src="https://github.com/user-attachments/assets/5ddb4aff-2ce4-481b-b8d4-a494d684db42" />

5. _Test the display to make sure it works before moving on_

<img width="400" alt="image" src="https://github.com/user-attachments/assets/5b157b1b-1039-4790-9187-62ae71f01079" />

6. Clean the silicone molds, **use a lint free cloth**
7. Mix and degass epoxy
8. Fill the half sphere cake mold with epoxy and gently place the display in the epoxy on the back surface, being careful to start at one side and gently lower against the face. You're trying to minimize bubbles at this stage, think about how you would apply a sticker. Another option to try is to pre-wet the display with epoxy as well before placing against the back surface of the mold.

<img width="400" alt="image" src="https://github.com/user-attachments/assets/7640b05d-fe77-4e17-a105-37df7b5d5a5b" />

# Odd limitations
There's a memory page limit(?) which restricts the array to 220 x 220 pixels. This is probably something that can be fixed or worked around in another way, but I just used a 220x220 centered frame then filled the outer 20pixels with black. When the eye is not cast in epoxy it's pretty visible but once embedded it's difficult to catch.
