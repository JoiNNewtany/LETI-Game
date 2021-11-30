#pragma once

class IListener {
    public:
        virtual ~IListener() {}
        virtual void update() = 0;
};
