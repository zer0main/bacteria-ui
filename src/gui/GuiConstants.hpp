/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */


#ifndef GUI_CONSTANTS_HPP
#define GUI_CONSTANTS_HPP

/** Color of center of bacterium; use to calculate team color */
const int DEFAULT_COLOR = 0xFFBA59;

/** Waiting time between moves (msec) */
const int MOVE_WAIT = 500;

/** Indent between minimum and default width/height */
const int INDENT = 15;

/** Maximum initial number of bacteria per team */
const int MAX_BACTERIA = 1000;

/** Maximum number of teams */
const int MAX_TEAMS = 100;

#endif
