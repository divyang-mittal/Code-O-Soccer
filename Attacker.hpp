#pragma once
#include "skills.h"
#include "math.h"

namespace MyStrategy
{
  void attacker(BeliefState *state,int botID)
  {
	Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
	/*if( Vec2D::distSq(state->homePos[botID],state->ballPos) < 2*BOT_BALL_THRESH)
		GoToPoint(botID,state,fpoint,PI/2,true,false);
	else 
		GoToPoint(botID,state,ballPoint,0,false, true);*/
/*	if ((state->awayPos[0].x > HALF_FIELD_MAXX - 400) && ((state->awayPos[0].y>OPP_GOAL_MINY - 300)&&(state->awayPos[0].y<OPP_GOAL_MINY + 300)))
	{

		Vec2D fpoint(HALF_FIELD_MAXX*(2/3), OPP_GOAL_MAXY-700);
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 2* BOT_BALL_THRESH)
			GoToPoint(botID, state, fpoint, PI / 2, true, false);
		else
			GoToPoint(botID, state, ballPoint, 0, false, true);
	}

	else
	{
		if ((state->awayPos[0].x > HALF_FIELD_MAXX - 400) && ((state->awayPos[0].y > OPP_GOAL_MAXY - 300) && (state->awayPos[0].y < OPP_GOAL_MAXY + 300)))
		{

			Vec2D fpoint(HALF_FIELD_MAXX*(2 / 3), OPP_GOAL_MINY + 700);
			if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 2 * BOT_BALL_THRESH)
				GoToPoint(botID, state, fpoint, PI / 2, true, false);
			else
				GoToPoint(botID, state, ballPoint, 0, false, true);
		}
	}*/
	if ((state->ballPos.x > 0) && (state->ballPos.y >= 0) && (state->ballPos.y < OPP_GOAL_MAXY))
	{
		Vec2D dpoint;
		dpoint.x = HALF_FIELD_MAXX + 1000;
		dpoint.y = OPP_GOAL_MINY+300;
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 4 * BOT_BALL_THRESH)
		{
			GoToBall(botID,state,true);
			GoToPoint(botID,state,dpoint,PI/2,true,true)
		}
		else
		{
			GoToPoint(botID, state, ballPoint, 0, false, true);
		}
	}
	else if ((state->ballPos.x>0) && (state->ballPos.y >0))
	{
		Vec2D fpoint(HALF_FIELD_MAXX, OUR_GOAL_MAXY);
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 3 * BOT_BALL_THRESH)
		{}	
			GoToBall(botID,state,true)
			GoToPoint(botID, state, fpoint, PI / 2, true, false);
		}
		else
			GoToPoint(botID, state, ballPoint, 0, false, false);

	}
	if ((state->ballPos.x>0) && (state->ballPos.y <= 0) && (state->ballPos.y > OPP_GOAL_MINY))
	{
		Vec2D dpoint;
		dpoint.x = -HALF_FIELD_MAXX + 1000;
		dpoint.y = OPP_GOAL_MAXY-300;
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 4 * BOT_BALL_THRESH)
		{
			GoToBall(botID,state,true);
			GoToPoint(botID,state,dpoint,PI/2,true,true)
		}
		else
		{
			GoToPoint(botID, state, ballPoint, 0, false, true);
		}
	}
	else if ((state->ballPos.x>0) && (state->ballPos.y < 0))
	{
		Vec2D fpoint(HALF_FIELD_MAXX, OPP_GOAL_MINY+200);
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 3 * BOT_BALL_THRESH)
			GoToPoint(botID, state, fpoint, PI / 2, true, false);
		else
			GoToPoint(botID, state, ballPoint, 0, false, false);

	}
		/*if (Vec2D::distSq(state->homePos[1], state->ballPos) < 2 * BOT_BALL_THRESH)
		{
			if (state->awayPos[0].y>0)
			{
				Spin(botID, MAX_BOT_OMEGA);
				//GoToPoint(botID, state, p1, atan((p1.y - y) / (p1.x - x)), true, true);
			}
			else if (state->awayPos[0].y < 0)
			{
				Spin(botID, MIN_BOT_OMEGA);
				//GoToPoint(botID, state, p2, atan((p2.y - y) / (p2.x - x)), true, true);
			}*/
	if (state->ballPos.x < 0)
	{
		Vec2D fpoint(HALF_FIELD_MAXX, 0);
		Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 4 * BOT_BALL_THRESH)
		{
			GoToBall(botID,state,true);
			GoToPoint(botID,state,fpoint,PI/2,true,true)
		else
			GoToPoint(botID, state, ballPoint, 0, false, true);
		}
	}


	
  }

  
