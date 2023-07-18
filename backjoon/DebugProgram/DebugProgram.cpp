#include <iostream>
#include <functional>

enum class SkillType
{
	Kick,
	Punch,
	GlobalKick
};

void GlobalKick();

class Player
{
public:
	Player();
	~Player();

	void ReadySkill(SkillType _Skill);
	void UseSkill();

	void Punch(int _Value);
	void Kick(int _Value, float _Value2);



private:
	SkillType CurrentSkill_;
	//전달받은 함수를 보관하는 변수
	//매게변수의 개수, 타입 상관x 반환 타입만 템플릿 인자에 적으면 됨(void())
	std::function<void()> UsingSkill;
};

void Player::ReadySkill(SkillType _Skill)
{
	switch (_Skill)
	{
	case SkillType::Kick:
		//bind(함수의 주소,인스턴스의 주소,매게 변수 값)
		UsingSkill = std::bind(&Player::Kick, this, 10, 3.8f);
		break;
	case SkillType::Punch:
		UsingSkill = std::bind(&Player::Punch, this, 5);
		break;
	case SkillType::GlobalKick:
		//bind(함수의 주소) << 전역 함수이니 인스턴스의 주소가 필요없다
		UsingSkill = std::bind(&GlobalKick);
		break;
	}
}

void Player::UseSkill()
{
	//UsingSkill에 연결된 함수를 호출
	UsingSkill();
}

void Player::Punch(int _Value)
{
	std::cout << "펀치 사용 " << _Value << "의 데미지 !!" << std::endl;
}

void Player::Kick(int _Value, float _Value2)
{
	std::cout << "킥 사용" << _Value << "의 데미지 !!" << _Value2 << "의 추가 데미지 !!" << std::endl;
}

void GlobalKick()
{
	std::cout << "글로벌 킥 사용" << std::endl;
}

int main()
{
	Player Bear;
	Bear.ReadySkill(SkillType::Punch);
	//Bear.ReadySkill(SkillType::Kick);
	//Bear.ReadySkill(SkillType::GlobalKick);
	//Bear.UseSkill();
}