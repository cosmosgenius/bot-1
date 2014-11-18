class Wheel
{
public:
  const unsigned char MINSPEED = 0;
  const unsigned char MAXSPEED = 255;

  const unsigned char FORWARD = 0;
  const unsigned char REVERSE = 1;
  Wheel();
  ~Wheel();
  
  void setSpeed(unsigned char);
  void setDirection(unsigned char);
};