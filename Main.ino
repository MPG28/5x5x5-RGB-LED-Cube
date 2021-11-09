
void loop() {

  sphere();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
  
  
  rotatingY();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
  
  sparkles();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 

  cubets1();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 

  crazy_box();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
  
  cornerBoxes();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
    
  panels();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
    
  cubets2();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
  
  rotator();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
  
  sinewave();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
  
//  cubeFlash();

  swings();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 
  
  cubet3();
  potentiometerValue = analogRead(POTENTIOMETER_PIN);
  brightness = map(potentiometerValue, 0, 1023, 3, 255);
  cube.setBrightness(brightness); 


}

// ***************************** Start of Cubets 1 2,3 *****************************************

void cubets1() {
    
  for (int i = 0; i < 100; i++) {
    mycolor++; if (mycolor > 42) mycolor = 1;
    cubet();
    showCube(4);
    moveCubet();
  }
  pause();
}
void cubets2() {
  for (int i = 0; i < 15; i++) {
    mycolor = mycolor + 10; if (mycolor > 42) mycolor = 1;
    bounceCubet();
  }
  pause();
}
void cubet3() {
  for (int j = 0; j < 3; j++) {
    mycolor = Red;
    for (int k = 0; k < 12; k++) {
      myloc[0] = pgm_read_byte_near(&cubetPath[k][0]);
      myloc[1] = pgm_read_byte_near(&cubetPath[k][1]);
      myloc[2] = pgm_read_byte_near(&cubetPath[k][2]);
      cubet(); showCube(2);
    }
  }
  for (int j = 0; j < 3; j++) {
    mycolor = Green;
    for (int k = 13; k < 25; k++) {
      myloc[0] = pgm_read_byte_near(&cubetPath[k][0]);
      myloc[1] = pgm_read_byte_near(&cubetPath[k][1]);
      myloc[2] = pgm_read_byte_near(&cubetPath[k][2]);
      cubet(); showCube(2);
    }
  }
  for (int j = 0; j < 3; j++) {
    mycolor = Blue;
    for (int k = 26; k < 38; k++) {
      myloc[0] = pgm_read_byte_near(&cubetPath[k][0]);
      myloc[1] = pgm_read_byte_near(&cubetPath[k][1]);
      myloc[2] = pgm_read_byte_near(&cubetPath[k][2]);
      cubet(); showCube(2);
    }
  }
  for (int j = 0; j < 3; j++) {
    mycolor = Green;
    for (int k = 0; k < 12; k++) {
      myloc[0] = pgm_read_byte_near(&cubetPath[k][0]);
      myloc[1] = pgm_read_byte_near(&cubetPath[k][1]);
      myloc[2] = pgm_read_byte_near(&cubetPath[k][2]);
      cubet(); showCube(2);
    }
  }
  for (int j = 0; j < 3; j++) {
    mycolor = Red;
    for (int k = 13; k < 25; k++) {
      myloc[0] = pgm_read_byte_near(&cubetPath[k][0]);
      myloc[1] = pgm_read_byte_near(&cubetPath[k][1]);
      myloc[2] = pgm_read_byte_near(&cubetPath[k][2]);
      cubet(); showCube(2);
    }
  }
  for (int j = 0; j < 3; j++) {
    mycolor = Blue;
    for (int k = 26; k < 38; k++) {
      myloc[0] = pgm_read_byte_near(&cubetPath[k][0]);
      myloc[1] = pgm_read_byte_near(&cubetPath[k][1]);
      myloc[2] = pgm_read_byte_near(&cubetPath[k][2]);
      cubet(); showCube(2);
    }
  }
  pause();
}


void cubet() { // range for x,y,z is 1-3
  int x = myloc[0]; int y = myloc[1]; int z = myloc[2];
  LED(x, y, z, mycolor);
  LED(x + 1, y, z, mycolor);
  LED(x, y + 1, z, mycolor);
  LED(x, y, z + 1, mycolor);
  LED(x + 1, y + 1, z, mycolor);
  LED(x, y + 1, z + 1, mycolor);
  LED(x + 1, y, z + 1, mycolor);
  LED(x + 1, y + 1, z + 1, mycolor);
}
void moveCubet() {
  int x = myloc[0];
  int y = myloc[1];
  int z = myloc[2];
  int k = random(6);
  switch (k) {
    case 0:
      if (x > 0)x--;
      else if (z < 3) z++;
      else z--;
      break;
    case 1:
      if (y > 0)y--;
      else if (x < 3) x++;
      else x--;
      break;
    case 2:
      if (z > 0)z--;
      else if (y < 3) y++;
      else y--;
      break;
    case 3:
      if (x < 3)x++;
      else if (z > 0) z--;
      else z++;
      break;
    case 4:
      if (y < 3)y++;
      else if (x > 0) x--;
      else x++;
      break;
    case 5:
      if (z < 3)z++;
      else if (y > 0) y--;
      else y++;
      break;
  }
  myloc[0] = x; myloc[1] = y; myloc[2] = z;
}
void bounceCubet() {
  myloc[0] = random(4);
  myloc[1] = random(4);
  for (int k = 0; k < 3; k++) {
    for (int j = k; j < 5; j++) {
      bouncer(j);
    }
  }
  myloc[2] = 0;
  cubet();
  showCube(10);
}

void bouncer(int k) {
  switch (k) {
    case 0:
      myloc[2] = 3;
      cubet();
      showCube(7);
      break;
    case 1:
      myloc[2] = 2;
      cubet();
      showCube(4);
      break;
    case 2:
      myloc[2] = 1;
      cubet();
      showCube(1); break;
    case 3:
      myloc[2] = 0;
      cubet();
      showCube(1);
      break;
    case 4:
      myloc[2] = 1;
      cubet();
      showCube(1);
      break;
  }
}
// *****************************  End of Cubets 1,2,3  ************************************

// *****************************  Beginning of RotatingY ************************************
void rotatingY() {
  for (int k = 0; k < 6; k++) {
    for (int j = 0; j < 8; j++) {
      rotY(j);
    }
  }
  pause();
}

// a colorful Y rotates around the Z axis
void rotY(int k) {
  switch (k) {
    case 0:
      for (int z = 0; z < 5; z++) {
        LED(2, 4, z, Orange);
        LED(2, 3, z, Orange);
        LED(2, 2, z, Green);
        LED(1, 1, z, Aqua);
        LED(0, 0, z, Aqua);
        LED(3, 1, z, Purple);
        LED(4, 0, z, Purple);
        }
      break;
    case 1:
      for (int z = 0; z < 5; z++) {
        LED(0, 4, z, Orange);
        LED(1, 3, z, Orange);
        LED(2, 2, z, Green);
        LED(2, 1, z, Aqua);
        LED(2, 0, z, Aqua);
        LED(3, 2, z, Purple);
        LED(4, 2, z, Purple);
      }
      break;  
    case 2:
      for (int z = 0; z < 5; z++) {
        LED(0, 2, z, Orange);
        LED(1, 2, z, Orange);
        LED(2, 2, z, Green);
        LED(3, 1, z, Aqua);
        LED(4, 0, z, Aqua);
        LED(3, 3, z, Purple);
        LED(4, 4, z, Purple);
        }
      break;
    case 3:
      for (int z = 0; z < 5; z++) {
        LED(0, 0, z, Orange);
        LED(1, 1, z, Orange);
        LED(2, 2, z, Green);
        LED(3, 2, z, Aqua);
        LED(4, 2, z, Aqua);
        LED(2, 3, z, Purple);
        LED(2, 4, z, Purple);
      }
      break;
    case 4:
      for (int z = 0; z < 5; z++) {
        LED(2, 0, z, Orange);
        LED(2, 1, z, Orange);
        LED(2, 2, z, Green);
        LED(3, 3, z, Aqua);
        LED(4, 4, z, Aqua);
        LED(1, 3, z, Purple);
        LED(0, 4, z, Purple);
      }
      break;
    case 5:
      for (int z = 0; z < 5; z++) {
        LED(4, 0, z, Orange);
        LED(3, 1, z, Orange);
        LED(2, 2, z, Green);
        LED(2, 3, z, Aqua);
        LED(2, 4, z, Aqua);
        LED(0, 2, z, Purple);
        LED(1, 2, z, Purple);
      }
      break;
    case 6:
      for (int z = 0; z < 5; z++) {
        LED(4, 2, z, Orange);
        LED(3, 2, z, Orange);
        LED(2, 2, z, Green);
        LED(0, 0, z, Aqua);
        LED(1, 1, z, Aqua);
        LED(0, 4, z, Purple);
        LED(1, 3, z, Purple);
      }
      break;
    case 7:
      for (int z = 0; z < 5; z++) {
        LED(4, 4, z, Orange);
        LED(3, 3, z, Orange);
        LED(2, 2, z, Green);
        LED(2, 0, z, Aqua);
        LED(2, 1, z, Aqua);
        LED(0, 2, z, Purple);
        LED(1, 2, z, Purple);
      }
      break;
  }
  showCube(5);
}
// *******************************  End of RotatingY ************************

// *******************************  Beginning of sphere ************************
// this routine creates a sphere in the cube of a specified radius
void sphere() {

  // this routine creates a sphere in the cube of a specified radius
  float count; mycolor = Red;
  for (int k = 0; k < 13; k++) {
    for (count = 0.5; count < 2.8; count = count + 0.3) { // expand the radius
      sphere(count);
    }
    for (count = 2.7; count > 0.5; count = count - 0.3) { // contaract the radius
      sphere(count);
    }
    mycolor = mycolor + 3;
  }
  pause();
}

// this routine creates a sphere in the cube of a specified radius
void sphere(float radius) {
  float polar, j, k, l;
  for (int x = 0; x < 5; x++) { // scan thru each led in the cube
    for (int y = 0; y < 5; y++) {
      for (int z = 0; z < 5; z++) {
        j = float(x); // convert coordinates to floating point to compute distance from center of cube
        k = float(y);
        l = float(z);
        polar = sqrt((j - 2) * (j - 2) + (k - 2) * (k - 2) + (l - 2) * (l - 2)); // Calculate the distance
        if (polar < radius) { // if an LED is inside the radius specified, turn it on.
          LED(x, y, z, mycolor);
        }
        else { // otherwise turn it off
          LED(x, y, z, Black);
        }
      }
    }
  }
  delay(5);  // control speed
}
// *******************************  End of sphere ************************


// *****************************  Beginning of Sparkles ************************************
void sparkles() {
  cube.setBrightness(brightness * 3);
  for (int j = 0; j < 125; j++) { // go around 75 times
    int newx1, newy1, newz1, newx2, newy2, newz2, newx3, newy3, newz3; // locations for 3 LEDs that are on at one time
    newx1 = random(5);
    newy1 = random(5);
    newz1 = random(5);
    LED(newx1, newy1, newz1, White); // create the first
    delay(3);
    LED(newx2, newy2, newz2, Black);  // turn off the second
    newx2 = random(5);
    newy2 = random(5);
    newz2 = random(5);
    LED(newx2, newy2, newz2, White); // create the first  // create the second
    delay(3);
    LED(newx3, newy3, newz3, Black);// turn off the third
    newx3 = random(5);
    newy3 = random(5);
    newz3 = random(5);
    LED(newx3, newy3, newz3, White); // create the first  // create the third
    delay(3);
    LED(newx1, newy1, newz1, Black);  // turn off the first
  }cube.setBrightness(brightness);
  pause();
}
// ***************************** End of Sparkles *****************************************

// ***************************** Start of Crazy Box *****************************************
void crazy_box() {
  int mydelay = 35;
  for (int k = 0; k < 12; k++) {
    for (int i = 0; i < 20; i++) {
      if (i < 5) {
        LED(0, 0, i % 5, mycolor);
        LED(0, 4, i % 5, mycolor);
        LED(4, 0, i % 5, mycolor);
        LED(4, 4, i % 5, mycolor);
        LED(i % 5, 0, 4, mycolor);
        LED(i % 5, 0, 0, mycolor);
        LED(4 - i % 5, 4, 4, mycolor);
        LED(4 - i % 5, 4, 0, mycolor);
      }
      else if (i > 4 && i < 10) {
        LED(0, 0, 4 - i % 5, mycolor);
        LED(0, 4, 4 - i % 5, mycolor);
        LED(4, 0, 4 - i % 5, mycolor);
        LED(4, 4, 4 - i % 5, mycolor);
        LED(4, i % 5, 4, mycolor);
        LED(4, i % 5, 0, mycolor);
        LED(0, 4 - i % 5, 4, mycolor);
        LED(0, 4 - i % 5, 0, mycolor);
      }
      else if (i > 9 && i < 15) {
        LED(0, 0, i % 5, mycolor);
        LED(0, 4, i % 5, mycolor);
        LED(4, 0, i % 5, mycolor);
        LED(4, 4, i % 5, mycolor);
        LED(i % 5, 0, 4, mycolor);
        LED(i % 5, 0, 0, mycolor);
        LED(4 - i % 5, 4, 4, mycolor);
        LED(4 - i % 5, 4, 0, mycolor);
      }
      else if (i > 14 && i < 20) {
        LED(0, 0, 4 - i % 5, mycolor);
        LED(0, 4, 4 - i % 5, mycolor);
        LED(4, 0, 4 - i % 5, mycolor);
        LED(4, 4, 4 - i % 5, mycolor);
        LED(0, 4 - i % 5, 4, mycolor);
        LED(0, 4 - i % 5, 0, mycolor);
        LED(4, i % 5, 4, mycolor);
        LED(4, i % 5, 0, mycolor);
      }
      delay(mydelay - 2 * k);
      if (i % 5 == 4) {
        clearCube();
        mycolor++;
        if (mycolor > 42) mycolor = 1;
      }
    }
    clearCube();
    delay(mydelay / 2);
    for (int i = 0; i < 5; i++) {
      LED(0, 0, 4 - i % 5, mycolor);
      LED(0, 4, 4 - i % 5, mycolor);
      LED(4, 0, 4 - i % 5, mycolor);
      LED(4, 4, 4 - i % 5, mycolor);
      LED(0, 4 - i % 5, 4, mycolor);
      LED(0, 4 - i % 5, 0, mycolor);
      LED(4 - i % 5, 4, 4, mycolor);
      LED(4 - i % 5, 4, 0, mycolor);
      LED(i % 5, 0, 4, mycolor);
      LED(i % 5, 0, 0, mycolor);
      LED(4, i % 5, 4, mycolor);
      LED(4, i % 5, 0, mycolor);
    }
    delay((mydelay - 2 * k) * 3);
    if (k > 10)delay(200);
    clearCube();
  }
  pause();
}
// ***************************** End of Crazy Box *****************************************

// *******************************  Begin cornerBoxes ************************
void cornerBoxes() {
  mycolor = 1;
  wireframer(0, 0, 0);
  wireframer(4, 4, 4);
  wireframer(0, 0, 4);
  wireframer(0, 4, 0);
  wireframer(4, 0, 0);
  wireframer(4, 4, 0);
  wireframer(0, 4, 4);
  wireframer(4, 0, 4);
  pause();
}
void wireframer(int x, int y, int z) {
  for (int j = 0; j < 4; j++) {
    for (int k = 1; k < 4; k++) {
      wireframe(x, y, z, k);
      showCube(2);
    }
    for (int k = 4; k > -1; k--) {
      wireframe(x, y, z, k );
      showCube(2);
    }
    mycolor++;
    if (mycolor > 42) mycolor = 1;
  }
}
void wireframe(int x1, int y1, int z1, int mysize)
{
  int i, x2, y2, z2;
  if (x1 == 0) x2 = x1 + mysize; else {
    x2 = x1;
    x1 = x2 - mysize;
  }
  if (y1 == 0) y2 = y1 + mysize; else {
    y2 = y1;
    y1 = y2 - mysize;
  }
  if (z1 == 0) z2 = z1 + mysize; else {
    z2 = z1;
    z1 = z2 - mysize;
  }
  // Lines along X axis
  for (i = x1; i <= x2; ++i)
  {
    LED(i, y1, z1, mycolor);
    LED(i, y1, z2, mycolor);
    LED(i, y2, z1, mycolor);
    LED(i, y2, z2, mycolor);
  }
  // Lines along Y axis
  for (i = y1; i <= y2; ++i)
  {
    LED(x1, i, z1, mycolor);
    LED(x1, i, z2, mycolor);
    LED(x2, i, z1, mycolor);
    LED(x2, i, z2, mycolor);
  }
  // Lines along Z axis
  for (i = z1; i <= z2; ++i)
  {
    LED(x1, y1, i, mycolor);
    LED(x1, y2, i, mycolor);
    LED(x2, y1, i, mycolor);
    LED(x2, y2, i, mycolor);
  }
}
// *******************************  End cornerBoxes ************************

// *******************************  Beginning of Panels ************************
void panels() {
  for (int k = 0; k < 2; k++) {
    for (int j = 0; j < 2; j++) {
      for (int z = 4; z > -1; z--) {
        for (int x = 0; x < 5; x++) {
          for (int y = 0; y < 5; y++) {
            redON(x, y, z);
          }
        }
        showCube(2);
      }
      for (int z = 0; z < 5; z++) {
        for (int x = 0; x < 5; x++) {
          for (int y = 0; y < 5; y++) {
            redON(x, y, z);
          }
        }
        showCube(2);
      }
    }
    for (int j = 0; j < 2; j++) {
      for (int x = 0; x < 5; x++) {
        for (int z = 0; z < 5; z++) {
          for (int y = 0; y < 5; y++) {
            blueON(x, y, z);
          }
        }
        showCube(2);
      }
      for (int x = 4; x > -1; x--) {
        for (int z = 0; z < 5; z++) {
          for (int y = 0; y < 5; y++) {
            blueON(x, y, z);
          }
        }
        showCube(2);
      }
    }
    for (int j = 0; j < 2; j++) {
      for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
          for (int z = 0; z < 5; z++) {
            greenON(x, y, z);
          }
        }
        showCube(2);
      }
      for (int y = 4; y > -1; y--) {
        for (int x = 0; x < 5; x++) {
          for (int z = 0; z < 5; z++) {
            greenON(x, y, z);
          }
        }
        showCube(2);
      }
    }
  }
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 3; k++) {
      for (int z = 4; z > -1; z--) {
        for (int x = 0; x < 5; x++) {
          for (int y = 0; y < 5; y++) {

            blueON(y, z, x);
            greenON(z, x, y);
          }
        }
        showCube(2);
      }
      for (int z = 0; z < 5; z++) {
        for (int x = 0; x < 5; x++) {
          for (int y = 0; y < 5; y++) {

            blueON(y, z, x);
            greenON(z, x, y);
          }
        }
        showCube(2);
      }
    }
    for (int k = 0; k < 3; k++) {
      for (int z = 4; z > -1; z--) {
        for (int x = 0; x < 5; x++) {
          for (int y = 0; y < 5; y++) {
            redON(x, y, z);
            greenON(z, x, y);
          }
        }
        showCube(2);
      }
      for (int z = 0; z < 5; z++) {
        for (int x = 0; x < 5; x++) {
          for (int y = 0; y < 5; y++) {
            redON(x, y, z);
            greenON(z, x, y);
          }
        }
        showCube(2);
      }
    }
    for (int k = 0; k < 3; k++) {
      for (int z = 4; z > -1; z--) {
        for (int x = 0; x < 5; x++) {
          for (int y = 0; y < 5; y++) {
            redON(x, y, z);
            blueON(y, z, x);

          }
        }
        showCube(2);
      }
      for (int z = 0; z < 5; z++) {
        for (int x = 0; x < 5; x++) {
          for (int y = 0; y < 5; y++) {
            redON(x, y, z);
            blueON(y, z, x);

          }
        }
        showCube(2);
      }
    }
  }
 /* for (int k = 0; k < 8; k++) {
    for (int z = 4; z > -1; z--) {
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
          redON(x, y, z);
          blueON(y, z, x);
          greenON(z, x, y);
        }
      }
      showCube(2);
    }
    for (int z = 0; z < 5; z++) {
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
          redON(x, y, z);
          blueON(y, z, x);
          greenON(z, x, y);
        }
      }
      showCube(2);
    }
  }           */
  pause();
}
// *******************************  End of Panels ************************


// ***************************** Beginning of Rotator *****************************************
// Rotates a panel around the center of the cube, rotating on the z axis
void rotator() {
  mycolor = 42;
  for (int k = 0; k < 2; k++) {
    for (int j = 7; j > 0; j--) {
      rotCenter(j);
    }
    mycolor = mycolor - 3;
    for (int j = 8; j > -1; j--) {
      rotCenter(j);
    }
    mycolor = mycolor - 3;
    for (int j = 7; j > 0; j--) {
      rotCenter(j);
    }
    mycolor = mycolor - 3;
    for (int j = 8; j > -1; j--) {
      rotCenter(j);
    }
    mycolor = mycolor - 3;
    for (int j = 0; j < 8; j++) {
      rotCenter(j);
    }
    mycolor = mycolor - 3;
    for (int j = 0; j < 9; j++) {
      rotCenter(j);
    }
    mycolor = mycolor - 3;
    for (int j = 0; j < 8; j++) {
      rotCenter(j);
    }
    mycolor = mycolor - 2;
    for (int j = 0; j < 9; j++) {
      rotCenter(j);
    }
  }
  pause();
}

// a vertical panel is spun around the center of the cube
// routine that does the rotatation
void rotCenter(int k) {
  switch (k) {
    case 0:
      for (int z = 0; z < 5; z++) {
        for (int x = 0; x < 5; x++) {
          LED(x, x, z, mycolor);
        }
      }
      break;
    case 1:
      for (int z = 0; z < 5; z++) {
        LED(0, 1, z, mycolor);
        LED(1, 1, z, mycolor);
        LED(2, 2, z, mycolor);
        LED(3, 3, z, mycolor);
        LED(4, 3, z, mycolor);
      }
      break;
    case 2:
      for (int z = 0; z < 5; z++) {
        LED(0, 2, z, mycolor);
        LED(1, 2, z, mycolor);
        LED(2, 2, z, mycolor);
        LED(3, 2, z, mycolor);
        LED(4, 2, z, mycolor);
      }
      break;
    case 3:
      for (int z = 0; z < 5; z++) {
        LED(0, 3, z, mycolor);
        LED(1, 2, z, mycolor);
        LED(2, 2, z, mycolor);
        LED(3, 2, z, mycolor);
        LED(4, 1, z, mycolor);
      }
      break;
    case 4:
      for (int z = 0; z < 5; z++) {
        LED(0, 4, z, mycolor);
        LED(1, 3, z, mycolor);
        LED(2, 2, z, mycolor);
        LED(3, 1, z, mycolor);
        LED(4, 0, z, mycolor);
      }
      break;
    case 5:
      for (int z = 0; z < 5; z++) {
        LED(1, 4, z, mycolor);
        LED(1, 3, z, mycolor);
        LED(2, 2, z, mycolor);
        LED(3, 1, z, mycolor);
        LED(3, 0, z, mycolor);
      }
      break;
    case 6:
      for (int z = 0; z < 5; z++) {

        LED(2, 0, z, mycolor);
        LED(2, 1, z, mycolor);
        LED(2, 2, z, mycolor);
        LED(2, 3, z, mycolor);
        LED(2, 4, z, mycolor);
      }
      break;
    case 7:
      for (int z = 0; z < 5; z++) {

        LED(1, 0, z, mycolor);
        LED(2, 1, z, mycolor);
        LED(2, 2, z, mycolor);
        LED(2, 3, z, mycolor);
        LED(3, 4, z, mycolor);
      }
      break;
    case 8:
      for (int z = 0; z < 5; z++) {
        for (int x = 0; x < 5; x++) {
          LED(x, x, z, mycolor);
        }
      }
      break;
  }
  showCube(2);
}
// *******************************  End of Rotator ************************

// ******************************* Biginning of Sinewave ************************
void sinewave() {
  mycolor = 1;
  for (int k = 0; k < 20; k++) {
    byte z = 0;
    mycolor += 2; if (mycolor > 42) mycolor = 0;
    for (int i = 0; i < 40; i++) { //it takes 40 steps to complete one full cycle
      for (byte xx = 0; xx < 3; xx++) { // for 1 quadrant of the cube
        for (byte yy = 0; yy < 3; yy++) {
          // the next line is the guts of the calculation, where the z value is calculated both as a function of i and distance
          // from center of cube.  The calculation is time consuming, so we calculate it for only one quadrant and
          // then reflect it onto the other 3 quadrants.
          z = ((byte)(2.5 + cos((xx / 1.39) + (yy / 1.39) + (float)i / 6.28) * 2.5)); // the actual z calculation
          LED(xx, yy, z, mycolor); // put z into the proper place for each position in quadrant 1
          LED(4 - xx, yy, z, mycolor); // put z into the proper place for each position in quatrant 2
          LED(xx, 4 - yy, z, mycolor); // put z into the proper place for each position in quatrant 4
          LED(4 - xx, 4 - yy, z, mycolor); // put z into the proper place for each position in quatrant 3
        }
      }
      delay(15);       // Increase or decrease to change speed of this animation
      clearCube();    // clear the cube
    }
  }
}
// *******************************  End of Sinewave ************************

// *******************************  Beginning of CubeFlash ************************
/*void cubeFlash() {
  for (int k = 0; k < 12; k++) {
    mycolor = 1 + k * 5;
    if (k > 6) {
      mycolor = White;
      cube.setBrightness(brightness * 4);
    }
    cubeInCube(0);
    showCube(3);
    cubeInCube(1);
    showCube(2);
    cubeInCube(2);
    showCube(3);
    cubeInCube(1);
    showCube(2 );
    if (k == 6) delay(200);
  }
  cube.setBrightness(brightness);
  pause();
}

// generate patterns from center on one layer
void cubeInCube(int k) {
  switch (k) {
    case 0:   // turn on center LED only
      LED(2, 2, 2, mycolor);
      break;
    case 1:    // turn on all but outside layers of cube
      for (int layer = 1; layer < 4; layer++) {
        for (int column = 1; column < 4; column++) {
          for (int row = 1; row < 4; row++) {
            LED(column, row, layer, mycolor);
          }
        }
      }
      LED(2, 2, 2, Black); //  and turn off the center
      break;
    case 2:  // turn on whole cube
      for (int layer = 0; layer < 5; layer++) {
        for (int column = 0; column < 5; column++) {
          for (int row = 0; row < 5; row++) {
            LED(column, row, layer, mycolor);
          }
        }
      }
      for (int layer = 1; layer < 4; layer++) {  // but turn off everything on the inside
        for (int column = 1; column < 4; column++) {
          for (int row = 1; row < 4; row++) {
            LED(column, row, layer, Black);
          }
        }
      }
      break;
  }
}  */
// *******************************  End of CubeFlash ************************


// *******************************  Beginning of Swings ************************
// these are classic cube animatios where a panel is lit and then swings around one axis to another panel
// we have a bunch of support routines - one for y axis, one for x axis, and 4 axis, one for each corner
void swings() {
  int wait = 25;  // the separation between various swings
  for (int j = 0; j < 5; j++) {
    ySwing(j, 0);
  }
  for (int j = 4; j > -1; j--) {
    ySwing(j, 0);
  }
  for (int j = 0; j < 5; j++) {
    xSwing(j, 0);
  }
  for (int j = 4; j > -1; j--) {
    xSwing(j, 0);
  }
  for (int j = 0; j < 5; j++) {
    ySwing(j, 1);
  }
  for (int j = 4; j > -1; j--) {
    ySwing(j, 1);
  }
  for (int j = 0; j < 5; j++) {
    xSwing(j, 1);
  }
  for (int j = 4; j > -1; j--) {
    xSwing(j, 1);
  }
  for (int j = 0; j < 5; j++) {
    ySwing(j, 2);
  }
  for (int j = 4; j > -1; j--) {
    ySwing(j, 2);
  }
  for (int j = 0; j < 5; j++) {
    xSwing(j, 2);
  }
  for (int j = 4; j > -1; j--) {
    xSwing(j, 2);
  }
  delay(wait); delay(wait);
  mycolor = Red;
  for (int j = 0; j < 5; j++) {
    zSwing0(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing1(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing2(j);
  }
  for (int j = 0; j < 5; j++) { 
    zSwing3(j);
  }
  delay(wait);
  mycolor = Green;
  for (int j = 0; j < 5; j++) {
    zSwing0(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing1(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing2(j);
  }
  for (int j = 0; j < 5; j++) {  
    zSwing3(j);
  }
  delay(wait);
  mycolor = Blue;
  for (int j = 0; j < 5; j++) {
    zSwing0(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing1(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing2(j);
  }
  for (int j = 0; j < 5; j++) { 
    zSwing3(j);
  }
  delay(wait);
  mycolor = White;
  for (int j = 0; j < 5; j++) {
    zSwing0(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing1(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing2(j);
  }
  for (int j = 0; j < 5; j++) { 
    zSwing3(j);
  }
  delay(wait);

  for (int j = 0; j < 5; j++) {
    ySwing(j, 3);
  }
  for (int j = 4; j > -1; j--) {
    ySwing(j, 3);
  }
  for (int j = 0; j < 5; j++) {
    xSwing(j, 3);
  }
  for (int j = 4; j > -1; j--) {
    xSwing(j, 3);
  }
  delay(wait);
  for (int j = 0; j < 5; j++) {
    ySwing(j, 3);
  }
  for (int j = 4; j > -1; j--) {
    ySwing(j, 3);
  }
  for (int j = 0; j < 5; j++) {
    xSwing(j, 3);
  }
  for (int j = 4; j > -1; j--) {
    xSwing(j, 3);
  }
  delay(wait);
  for (int j = 0; j < 5; j++) {
    ySwing(j, 5);
  }
  for (int j = 4; j > -1; j--) {
    ySwing(j, 5);
  }
  for (int j = 0; j < 5; j++) {
    xSwing(j, 5);
  }
  for (int j = 4; j > -1; j--) {
    xSwing(j, 5);
  }
  delay(wait); delay(wait);
  mycolor = Yellow;
  for (int j = 0; j < 5; j++) {
    zSwing0(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing1(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing2(j);
  }
  for (int j = 0; j < 5; j++) { 
    zSwing3(j);
  }
  delay(wait);
  mycolor = Aqua;
  for (int j = 0; j < 5; j++) {
    zSwing0(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing1(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing2(j);
  }
  for (int j = 0; j < 5; j++) {  
    zSwing3(j);
  }
/*  delay(wait);
  mycolor = Purple;
  for (int j = 0; j < 5; j++) {
    zSwing0(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing1(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing2(j);
  }
  for (int j = 0; j < 5; j++) { 
    zSwing3(j);
  }
  delay(wait); */
/*  mycolor = White;
  for (int j = 0; j < 5; j++) {
    zSwing0(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing1(j);
  }
  for (int j = 0; j < 5; j++) {
    zSwing2(j);
  }
  for (int j = 0; j < 5; j++) {  
    zSwing3(j);
  } */
/*  delay(wait);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      ySwing(j, 6);
    }
    for (int j = 4; j > -1; j--) {
      ySwing(j, 6);
    }
    for (int j = 0; j < 5; j++) {
      xSwing(j, 6);
    }
    for (int j = 4; j > -1; j--) {
      xSwing(j, 6);
    }
  } */
  pause();
}

// swing a panel around a axis, the axis depend on color
// 7 modes - 0,1,2 are on panel, 1 color; 3,4,5 are 2 panels, 2 colors
// mode 6 is 3 panels, 3 colors
void ySwing(int k, byte mode) {
  switch (k) {
    case 0:
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
          if (mode == 0 || mode == 3 || mode == 4 ) redON(x, y, 0);
          if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 0, x);
          if (mode == 2 || mode == 4 || mode == 5 ) blueON(0, x, y);
        }
      }
      break;
    case 1:
      for (int y = 0; y < 5; y++) {
        if (mode == 0 || mode == 3 || mode == 4 ) redON(4, y, 0);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 0, 4);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(0, 4, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(3, y, 0);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 0, 3);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(0, 3, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(2, y, 1);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 1, 2);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(1, 2, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(1, y, 1);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 1, 1);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(1, 1, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(0, y, 2);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 2, 0);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(2, 0, y);
      }
      break;
    case 2:
      for (int y = 0; y < 5; y++) {
        if (mode == 0 || mode == 3 || mode == 4 ) redON(4, y, 0);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 0, 4);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(0, 4, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(3, y, 1);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 1, 3);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(1, 3, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(2, y, 2);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 2, 2);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(2, 2, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(1, y, 3);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 3, 1);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(3, 1, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(0, y, 4);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 4, 0);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(4, 0, y);
      }
      break;
    case 3:
      for (int y = 0; y < 5; y++) {
        if (mode == 0 || mode == 3 || mode == 4 ) redON(4, y, 0);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 0, 4);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(0, 4, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(4, y, 1);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 1, 4);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(1, 4, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(3, y, 2);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 2, 3);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(2, 3, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(3, y, 3);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 3, 3);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(3, 3, y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(2, y, 4);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, 4, 2);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(4, 2, y);
      }
      break;
     case 4:
      for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
          if (mode == 0 || mode == 3 || mode == 4 ) redON(4, y, z);
          if (mode == 1 || mode == 3 || mode == 5 ) greenON(y, z, 4);
          if (mode == 2 || mode == 4 || mode == 5 ) blueON(z, 4, y);
        }
      }
      break;   
  }
  if (mode < 3) showCube(2);
  else if (mode == 6) showCube(4);
  else showCube(3);
}

// same as ySwing, but everything reflected to opposite corner of cube
void xSwing(int k, byte mode) {
  switch (k) {
    case 0:
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
          if (mode == 0 || mode == 3 || mode == 4 ) redON(4 - x, 4 - y, 4);
          if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 4, 4 - x);
          if (mode == 2 || mode == 4 || mode == 5 ) blueON(4, 4 - x, 4 - y);
        }
      }
      break;
    case 1:
      for (int y = 0; y < 5; y++) {
        if (mode == 0 || mode == 3 || mode == 4 ) redON(0, 4 - y, 4);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 4, 0);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(4, 0, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(1, 4 - y, 4);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 4, 1);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(4, 1, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(2, 4 - y, 3);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 3, 2);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(3, 2, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(3, 4 - y, 3);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 3, 3);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(3, 3, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(4, 4 - y, 2);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 2, 4);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(2, 4, 4 - y);
      }
      break;
    case 2:
      for (int y = 0; y < 5; y++) {
        if (mode == 0 || mode == 3 || mode == 4 ) redON(0, 4 - y, 4);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 4, 0);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(4, 0, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(1, 4 - y, 3);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 3, 1);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(3, 1, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(2, 4 - y, 2);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 2, 2);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(2, 2, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(3, 4 - y, 1);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 1, 3);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(1, 3, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(4, 4 - y, 0);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 0, 4);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(0, 4, 4 - y);
      }
      break;
    case 3:
      for (int y = 0; y < 5; y++) {
        if (mode == 0 || mode == 3 || mode == 4 ) redON(0, 4 - y, 4);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 4, 0);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(4, 0, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(0, 4 - y, 3);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 3, 0);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(3, 0, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(1, 4 - y, 2);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 2, 1);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(2, 1, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(1, 4 - y, 1);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 1, 1);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(1, 1, 4 - y);
        if (mode == 0 || mode == 3 || mode == 4 ) redON(2, 4 - y, 0);
        if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 0, 2);
        if (mode == 2 || mode == 4 || mode == 5 ) blueON(0, 2, 4 - y);
      }
      break;
    case 4:
      for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
          if (mode == 0 || mode == 3 || mode == 4 ) redON(0, 4 - y, 4 - z);
          if (mode == 1 || mode == 3 || mode == 5 ) greenON(4 - y, 4 - z, 0);
          if (mode == 2 || mode == 4 || mode == 5 ) blueON(4 - z, 0, 4 - y);
        }
      }
      break; 
  }
  if (mode < 3) showCube(2);
  else if (mode == 6) showCube(4);
  else showCube(3);
}

// swing a panel around the z axis
void zSwing0(int k) {
  switch (k) {
    case 0:
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
          LED(x, 0, y, mycolor);
        }
      }
      break;
    case 1:
      for (int y = 0; y < 5; y++) {
        LED(4, 0, y, mycolor);
        LED(3, 0, y, mycolor);
        LED(2, 1, y, mycolor);
        LED(1, 1, y, mycolor);
        LED(0, 2, y, mycolor);
      }
      break;
    case 2:
      for (int y = 0; y < 5; y++) {
        LED(4, 0, y, mycolor);
        LED(3, 1, y, mycolor);
        LED(2, 2, y, mycolor);
        LED(1, 3, y, mycolor);
        LED(0, 4, y, mycolor);
      }
      break;
    case 3:
      for (int y = 0; y < 5; y++) {
        LED(4, 0, y, mycolor);
        LED(4, 0, y, mycolor);
        LED(3, 2, y, mycolor);
        LED(3, 3, y, mycolor);
        LED(2, 4, y, mycolor);
      }
      break;
    case 4:
      for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
          LED(4, y, z, mycolor);
        }
      }
      break; 
  }
  showCube(2);
}

void zSwing1(int k) {
  switch (k) {
    case 0:
      for (int x = 0; x < 5; x++) {
        for (int z = 0; z < 5; z++) {
          LED(4, x, z, mycolor);
        }
      }
      break;
    case 1:
      for (int y = 0; y < 5; y++) {
        LED(2, 0, y, mycolor);
        LED(3, 1, y, mycolor);
        LED(3, 2, y, mycolor);
        LED(4, 3, y, mycolor);
        LED(4, 4, y, mycolor);
      }
      break;
    case 2:
      for (int y = 0; y < 5; y++) {
        LED(0, 0, y, mycolor);
        LED(1, 1, y, mycolor);
        LED(2, 2, y, mycolor);
        LED(3, 3, y, mycolor);
        LED(4, 4, y, mycolor);
      }
      break;
    case 3:
      for (int y = 0; y < 5; y++) {
        LED(0, 2, y, mycolor);
        LED(1, 3, y, mycolor);
        LED(2, 3, y, mycolor);
        LED(3, 4, y, mycolor);
        LED(4, 4, y, mycolor);
      }
      break;
    case 4:
      for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
          LED(y, 4, z, mycolor);
        }
      }
      break;  
  }
  showCube(2);
}
void zSwing2(int k) {
  switch (k) {
    case 0:
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
          LED(x, 4, y, mycolor);
        }
      }
      break;
    case 1:
      for (int y = 0; y < 5; y++) {
        LED(4, 2, y, mycolor);
        LED(3, 3, y, mycolor);
        LED(2, 3, y, mycolor);
        LED(1, 4, y, mycolor);
        LED(0, 4, y, mycolor);
      }
      break;
    case 2:
      for (int y = 0; y < 5; y++) {
        LED(4, 0, y, mycolor);
        LED(3, 1, y, mycolor);
        LED(2, 2, y, mycolor);
        LED(1, 3, y, mycolor);
        LED(0, 4, y, mycolor);
      }
      break;
    case 3:
      for (int y = 0; y < 5; y++) {
        LED(2, 0, y, mycolor);
        LED(1, 1, y, mycolor);
        LED(1, 2, y, mycolor);
        LED(0, 3, y, mycolor);
        LED(0, 4, y, mycolor);
      }
      break;
    case 4:
      for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
          LED(0, y, z, mycolor);
        }
      }
      break; 
  }
  showCube(2);
}  
 void zSwing3(int k) {
  switch (k) {
    case 0:
      for (int x = 0; x < 5; x++) {
        for (int z = 0; z < 5; z++) {
          LED(0, x, z, mycolor);
        }
      }
      break;
    case 1:
      for (int y = 0; y < 5; y++) {
        LED(0, 0, y, mycolor);
        LED(0, 1, y, mycolor);
        LED(1, 2, y, mycolor);
        LED(1, 3, y, mycolor);
        LED(2, 4, y, mycolor);
      }
      break;
    case 2:
      for (int y = 0; y < 5; y++) {
        LED(0, 0, y, mycolor);
        LED(1, 1, y, mycolor);
        LED(2, 2, y, mycolor);
        LED(3, 3, y, mycolor);
        LED(4, 4, y, mycolor);
      }
      break;
    case 3:
      for (int y = 0; y < 5; y++) {
        LED(0, 0, y, mycolor);
        LED(1, 0, y, mycolor);
        LED(2, 1, y, mycolor);
        LED(3, 1, y, mycolor);
        LED(4, 2, y, mycolor);
      }
      break;
    case 4:
      for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
          LED(y, 0, z, mycolor);
        }
      }
      break;  
  }
  showCube(2);
} 
// *******************************  End of Swings ************************
