#include "framework/charles.h"
#include "assignments/assignment2.h"

void test_agent() {

}

void return_to_path() {
    turn_right();
    turn_right();
    step();
    turn_right();
}

bool has_ball_on_side() {
    turn_right();
    turn_right();
    step();
    turn_right();
    step();

    return on_ball();
}

void end_facing_east() {
    turn_right();
    turn_right();
    step();
    turn_right();
    turn_right();
    turn_right();
    step();
}

void path_agent() {
    while (on_ball())
    {   
        step();
        if (!on_ball()) {
            if (north()) {
                if (has_ball_on_side()) {
                    step();
                }
                else {
                    turn_right();
                    step();   
                }
            }
            else {
                return_to_path();
            }
        }
    }
    end_facing_east();
}

void walk_up_and_down_and_right() {
while (!in_front_of_wall())
{
    if (!on_ball()) {
        put_ball();
    }
    step();
    if (in_front_of_wall())
    {
        if (north())
        {
            turn_right();
            step();
            turn_right();
        }
        else{
            turn_right();
            turn_right();
        }
    }
}
}

void walk_up_and_down_and_left() {
while (!in_front_of_wall())
{
    if (!on_ball()) {
        put_ball();
    }
    step();
    if (in_front_of_wall())
    {
        if (north())
        {
            turn_left();
            step();
            turn_left();
        }
        else{
            turn_right();
            step();
            turn_right();
        }
    }
}
}

void walk_out_of_small_space_1() {
    if (!on_ball()) {
        put_ball();
    }
    turn_left();
    step();
    if (!on_ball()) {
        put_ball();
    }
    step();
    if (!on_ball()) {
        put_ball();
    }
    step();
    if (!on_ball()) {
        put_ball();
    }
    turn_right();
}

void walk_out_of_small_space_2() {
    if (!on_ball()) {
        put_ball();
    }
    turn_left();
    step();
    turn_right();
}

// NOTE: this agent is executed twice in a row. See the PDF for more details.
void cave_agent() {
    step();
    turn_right();

    walk_up_and_down_and_right();
    walk_out_of_small_space_1();

    walk_up_and_down_and_right();
    walk_out_of_small_space_2();

    walk_up_and_down_and_right();
    walk_out_of_small_space_2();

    walk_up_and_down_and_left();
}
