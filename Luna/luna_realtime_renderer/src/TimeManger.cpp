#include "TimeManger.hpp"

namespace luna
{
    TimeManager::TimeManager() : mTimeStarted{glfwGetTime()}
    {

    }

    double TimeManager::GetCurrentTime() const
    {
        return glfwGetTime();
    }

    double TimeManager::GetDeltaTime() const
    {
        return mDeltaTime;
    }

    double TimeManager::GetFPS() const
    {
        return mFrameCount / (GetCurrentTime() - mTimeStarted);
    }

    // Call for every frame
    void TimeManager::UpdateTime()
    {
        double currentTime = GetCurrentTime();
        mDeltaTime = currentTime - mLastFrameTime;
        mLastFrameTime = currentTime;
        mFrameCount +=1;
    }
}
