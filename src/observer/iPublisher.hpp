#pragma once

class IListener;

class IPublisher {
    public:
        virtual ~IPublisher() {}
        virtual void subscribe(IListener*) = 0;
        virtual void unsubscribe(IListener*) = 0;
        virtual void notify() = 0;
};
