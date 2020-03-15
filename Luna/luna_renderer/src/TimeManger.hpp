#ifndef TIMEMANAGER_HPP
#define TIMEMANAGER_HPP
#include <GLFW/glfw3.h>

namespace  luna
{
    class TimeManager
    {
    public:
        TimeManager();
        double GetCurrentTime() const;
        double GetDeltaTime() const;
        double GetFPS() const;
        void UpdateTime();

    private:
        double mTimeStarted;
        double mDeltaTime = 0;
        int mFrameCount = 0;
        double mLastFrameTime = 0.0;
    };
}
#endif
