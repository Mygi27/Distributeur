#ifndef button_hpp
#define button_hpp

class button{
protected: 
  bool status = 0;
  const int buttonPin;
public:
    button();
    ~button();
    bool isPressed();
};

#endif