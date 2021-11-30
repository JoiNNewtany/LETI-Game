#pragma once

#include <list>
#include "observer/iPublisher.hpp"
#include "observer/iListener.hpp"

class Publisher : public IPublisher {
    public:
        Publisher() {}
        ~Publisher() {}

        virtual void subscribe(IListener* l) override {
            subscribers.push_back(l);
        }

        virtual void unsubscribe(IListener* l) override {
            subscribers.remove(l);
        }

        virtual void notify() override {
            for (auto subscriber : subscribers)
                subscriber->update();
        }

    protected:
        std::list<IListener*> subscribers;
};
