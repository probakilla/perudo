#include "player.hpp"

/* ==== SYMBOLIC CONSTANTS ==== */
const int STARTING_DICE_COUNT = 5;
const int MAXIMUM_DICES = 10;
const int MINIMUM_DICES = 1;
/* ==== SYMBOLIC CONSTANTS ==== */

Player::Player () : _dices_value (5){}
Player::~Player () {}

int Player::dice_nb () const
{
  return _dices_value.size();
}

vector<int> Player::get_dices_value ()
{
  // Normalement la copie se deroule bien...
  vector<int> v_ret = _dices_value;
  return v_ret;
}


void Player::roll_dices ()
{
  int i, random;
  srand (time(0));
  for (i=0; i<=_dices_value.size(); ++i)
  {
    random = rand() % 6;
    _dices_value.at(i) = random;
  }
}

int Player::occ_nb (int value, bool palifico)
{
  int count = 0;
  int i;
  if (!palifico)
  {
    for (i=0; i<_dices_value.size(); ++i)
      if (_dices_value.at(i) == value || _dices_value.at(i) == 1) {++count;}
  }
  else
    for (i=0; i<_dices_value.size(); ++i)
      if (_dices_value.at(i) == value) ++count;
    return count;
}

Player Player::operator ++ ()
{
  if (_dices_value.size () <= MAXIMUM_DICES)
  {
    _dices_value.push_back(0);
  }
}

Player Player::operator -- ()
{
  if (_dices_value.size() <= MINIMUM_DICES)
  {
    _dices_value.resize(_dices_value.size()-1);
  }
}