#pragma once

// �I�u�W�F�N�g�N���X player, enemy, shot
class Object {
protected:
	int size;		// �摜�T�C�Y

public:
	double x, y;	// x���W�Ay���W
	int hit_size;	// �����蔻��̃T�C�Y
	bool flag;		// �L���t���O

	virtual void Update() {}	// �X�V
	virtual void Draw() {}		// �`��
	virtual void CollisionResult() {}	// �����蔻���̏���
};

