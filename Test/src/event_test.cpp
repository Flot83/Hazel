#include "Hazel/Events/Events.h"

#include <gtest/gtest.h> // googletest header file

TEST(KeyPressedEvent, GetName) {

    Hazel::KeyPress key;
    EXPECT_STREQ(key.GetName(), "KeyPress");
}

TEST(KeyPressedEvent, GetEventType) {
    Hazel::KeyPress key;
    EXPECT_EQ(key.GetEventType(), Hazel::EventType::KeyPressed);
}
