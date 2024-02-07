// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일

#include "pch.h"

// 미리 컴파일된 헤더를 사용하는 경우 컴파일이 성공하려면 이 소스 파일이 필요합니다.

MoveState* MoveState::GetInstance()
{
    if (instance == nullptr) instance = new MoveState();
    return instance;
}

void MoveState::Move(Character* ch)
{
    cout << "(Move) 걷는중..." << endl;
}

void MoveState::Attack(Character* ch)
{
    cout << "(Move) 걷던 중 적 발견, 공격 개시" << endl;
    SetCharacterState(ch, AttackState::GetInstance());
}

void MoveState::Idle(Character* ch)
{
    cout << "(Move) 쉴 준비 끝" << endl;
    SetCharacterState(ch, IdleState::GetInstance());
}

// =============================== attack ============================

AttackState* AttackState::GetInstance()
{
    if (instance == nullptr) instance = new AttackState();
    return instance;
}

void AttackState::Move(Character* ch)
{
    cout << "(attack) 공격 도중에는 못걷는다" << endl;
}

void AttackState::Attack(Character* ch)
{
    cout << "(attack) 공격하여 적을 없애고 휴식" << endl;
    SetCharacterState(ch, IdleState::GetInstance());
}

void AttackState::Idle(Character* ch)
{
    cout << "(attack) 공격 도중에는 못쉰다." << endl;
}

// =============================== idle ============================

IdleState* IdleState::GetInstance()
{
    if (instance == nullptr) instance = new IdleState();
    return instance;
}

void IdleState::Move(Character* ch)
{
    cout << "(idle) 휴식 끝, 걷기 시작" << endl;
    SetCharacterState(ch, MoveState::GetInstance());
}

void IdleState::Attack(Character* ch)
{
    cout << "(idle) 쉬던 중 적 발견, 공격" << endl;
    SetCharacterState(ch, AttackState::GetInstance());
}

void IdleState::Idle(Character* ch)
{
    cout << "(idle) 쉬는 중" << endl;
}

// =========================== 캐릭터 =========================

Character::Character()
{
    state = IdleState::GetInstance();
}

void Character::SetState(StateMachine* state)
{
    this->state = state;
}

void Character::move()
{
    state->Move(this);
}

void Character::attack()
{
    state->Attack(this);
}

void Character::idle()
{
    state->Idle(this);
}
