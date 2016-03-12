/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

namespace Gui {

/** The proportion of a team color's size in a cell
Teams number <= MIN_TEAMS
*/
const double MIN_SIZE_PROPORTION = 0.125;

/** The proportion of a team color's size in a cell
Teams number > MIN_TEAMS
*/
const double MAX_SIZE_PROPORTION = 0.550;

const int MIN_TEAMS = 8;

}

#endif
