#include "Hazel/Events/KeyEvent.h"

#include <gtest/gtest.h> // googletest header file


TEST(KeyPressedEvent, TestInterface) {
    Hazel::KeyPressedEvent key(12, 12);
    EXPECT_STREQ(key.GetName(), "KeyPressed");
    EXPECT_EQ(key.GetKeyCode(), 12);
    EXPECT_EQ(key.GetCategoryClass(), Hazel::EventCategory::EventCategoryInput | Hazel::EventCategory::EventCategoryKeyboard);
    EXPECT_EQ(key.GetEventType(), Hazel::EventType::KeyPressed);

    Hazel::Event& keyRef = key;
    EXPECT_EQ(keyRef.GetEventType(), Hazel::EventType::KeyPressed);

    EXPECT_FALSE(key.IsHandled());
    key.SetEventHandled();
    EXPECT_TRUE(key.IsHandled());
}

TEST(EventDispatcher, Dispatch) {
    Hazel::KeyPressedEvent key(12, 12);

    auto OnKeyPressed = [](Hazel::KeyPressedEvent& event) -> bool
    {
        return true;
    };

    Hazel::Event& event = key;

    Hazel::EventDispatcher eventDispatcher(key);
    
    EXPECT_TRUE(eventDispatcher.Dispatch(OnKeyPressed));

    //EXPECT_EQ(key.IsHandled(), true);
}

