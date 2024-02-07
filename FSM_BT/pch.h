// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가

#endif //PCH_H
#include <iostream>

using namespace std;

class StateMachine;
class Character {
	StateMachine* state;
public: 
	Character();
	void SetState(StateMachine* state);
	void move();
	void attack();
	void idle();
};

class StateMachine {
public:
	virtual void Idle(Character* ch) = 0;
	virtual void Move(Character* ch) = 0;
	virtual void Attack(Character* ch) = 0;

protected:
	void SetCharacterState(Character* ch, StateMachine* state) {
		ch->SetState(state);
	}
};

class MoveState : public StateMachine {
	static MoveState* instance;
public:
	static MoveState* GetInstance();

	virtual void Idle(Character* ch);
	virtual void Move(Character* ch);
	virtual void Attack(Character* ch);
};

class AttackState : public StateMachine {
	static AttackState* instance;
public:
	static AttackState* GetInstance();

	virtual void Move(Character* ch);
	virtual void Attack(Character* ch);
	virtual void Idle(Character* ch);
};

class IdleState : public StateMachine {
	static IdleState* instance;
public:
	static IdleState* GetInstance();

	virtual void Move(Character* ch);
	virtual void Attack(Character* ch);
	virtual void Idle(Character* ch);
};

MoveState* MoveState::instance;
AttackState* AttackState::instance;
IdleState* IdleState::instance;

