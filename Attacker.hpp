#pragma once
#include "skills.h"
#include "math.h"

namespace MyStrategy
{
  void attacker(BeliefState *state,int botID)
  {
	Vec2D opp1;
	opp1.x = state->awayPos[1].x;
	opp1.y = state->awayPos[1].y;
    //print("Attacker\n");
	Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
	// Go to ball if ball is far
	// Take ball to the goal
	/*if( Vec2D::distSq(state->homePos[botID],state->ballPos) < 2*BOT_BALL_THRESH)
		GoToPoint(botID,state,fpoint,PI/2,true,false);
	else 
		GoToPoint(botID,state,ballPoint,0,false, true);*/
	if (state->ballPos.x<-HALF_FIELD_MAXX/4)
	{
		GoToPoint(botID, state, opp1, PI / 2, false, false);
	}
	if ((state->ballPos.x>0) && (state->ballPos.y < 0))
	{
		Vec2D fpoint(HALF_FIELD_MAXX, OPP_GOAL_MINY);
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 2 * BOT_BALL_THRESH)
			GoToPoint(botID, state, fpoint, PI / 2, true, false);
		else
			GoToPoint(botID, state, ballPoint, 0, false, false);

	}
	if ((state->ballPos.x>0) && (state->ballPos.y >0))
	{
		Vec2D fpoint(HALF_FIELD_MAXX, OPP_GOAL_MAXY);
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 2 * BOT_BALL_THRESH)
			GoToPoint(botID, state, fpoint, PI / 2, true, false);
		else
			GoToPoint(botID, state, ballPoint, 0, false, false);

	}
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
	int y21, y11, x2, x1,y22,y12,x,y;
	Vec2D p1;
	Vec2D p2;
	x1 = HALF_FIELD_MAXX/2;
	x2 = HALF_FIELD_MAXX;
	y21 = OUR_GOAL_MINY;
	y11 = -HALF_FIELD_MAXY / 2;
	y22 = OUR_GOAL_MAXY;
	y12 = HALF_FIELD_MAXY / 2;
	x = state->homePos[2].x;
	y = state->homePos[2].y;

	p1.x = HALF_FIELD_MAXX;
	p1.y = OPP_GOAL_MINY;
	p2.x = HALF_FIELD_MAXX;
	p2.y = OPP_GOAL_MAXY;
	if ((state->ballPos.x > 0) && (state->ballPos.y >= 0) && (state->ballPos.y < OPP_GOAL_MAXY))
	{
		Vec2D dpoint;
		dpoint.x = -HALF_FIELD_MAXX + 1000;
		dpoint.y = state->ballPos.y;
		if (Vec2D::distSq(state->homePos[2], state->ballPos) < 2 * BOT_BALL_THRESH)
		{
			Spin(botID, MAX_BOT_OMEGA);
		}
		else
		{
			GoToPoint(botID, state, ballPoint, 0, false, true);
		}
	}
	if ((state->ballPos.x>0) && (state->ballPos.y <= 0) && (state->ballPos.y > OPP_GOAL_MINY))
	{
		Vec2D dpoint;
		dpoint.x = -HALF_FIELD_MAXX + 1000;
		dpoint.y = state->ballPos.y;
		if (Vec2D::distSq(state->homePos[2], state->ballPos) < 2 * BOT_BALL_THRESH)
		{
			Spin(botID, MIN_BOT_OMEGA);
		}
		else
		{
			GoToPoint(botID, state, ballPoint, 0, false, true);
		}
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
			// Go to ball if ball is far
			// Take ball to the goal
			if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 2 * BOT_BALL_THRESH)
				GoToPoint(botID, state, fpoint, PI / 2, true, false);
			else
				GoToPoint(botID, state, ballPoint, 0, false, true);
		}
	}
  }

  
