int16_t mymap(int16_t x, int16_t lowfrom, int16_t highfrom, int16_t lowto, int16_t highto)
{
    if (x < lowfrom) return lowto;
    if (x > highfrom) return highto;
    return (lowto + (x-lowfrom)*(highto-lowto)/(highfrom-lowfrom));
}
  
  uint32_t getColor(double temp){
  uint32_t red = Adafruit_NeoPixel::Color(255, 0, 0);

  uint32_t yellow = Adafruit_NeoPixel::Color(255, 255, 0);
  
  uint32_t blue = Adafruit_NeoPixel::Color(0, 0, 255);
  
  uint8_t r, g, b;

  //hot = red 255, 0, 0
  if (temp >= 65) {
    return red;
  }

  //yellow = kind of hot 255, 255, 0
  else 
  if (temp >= 42) {
    r = 255;
    g = mymap(temp, 42, 65, 255, 0);
    b = 0;
    return Adafruit_NeoPixel::Color(r, g, b);
  }
  //green = room temp 21 0, 255, 0
  else if (temp >= 21) {
    r = mymap(temp, 21, 42, 0, 255);
    g = 255;
    b = 0;
    return Adafruit_NeoPixel::Color(r, g, b);
  }
  //cold = blue 0, 0, 255
  else if (temp >= 10) {
    r = 0;
    g = mymap(temp, 10, 21, 0, 255);
    b = mymap(temp, 10, 21, 255, 0);
    return Adafruit_NeoPixel::Color(r, g, b);
  }
  
  else {
    return blue;
  }
  
}
