#ifndef InputHandler_H
#define InputHandler_H

#include <vector>
#include <SDL2/SDL_joystick.h>

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler {

    public:
        static InputHandler *Instance()
        {
            if (s_pInstance == 0) s_pInstance = new InputHandler();
            return s_pInstance;
        }

        void initialiseJoysticks();
        bool joysticksInitialised() {return m_bJoysticksInitialised;}
        int xvalue(int joy, int stick);
        int yvalue(int joy, int stick);
        void update();
        void clean();

    
    private:
        InputHandler();
        ~InputHandler() {}

        std::vector<SDL_Joystick*> m_joysticks;
        std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
        bool m_bJoysticksInitialised;
        int m_joysticksDeadZone;
        std::vector<bool> m_mouseButtonStates;
        static InputHandler *s_pInstance;
};

#endif