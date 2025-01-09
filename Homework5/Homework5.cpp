// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "CoreMinimal.h"
#include <iostream>
using namespace std;

/*
������(0, 0) �ִ� ���� ĳ���Ͱ� �����ϰ� 10ȸ �̵� �մϴ�.�� ���ܿ��� ���İ� ��ǥ�� ��� ����ϴ°� �����Դϴ�.

���� �䱸������ �Ʒ��� �����ϴ�.

- ��������(0, 0)�̰� �ѹ� �̵��� x��ǥ�� y��ǥ ��� 2�̻� �̵��� �� �����ϴ�.���� ��� �Ʒ��� �����ϴ�.
- (0, 0) ����(1, 2)�� �̵��Ҽ� �����ϴ�.y��ǥ�� 2�̻� �̵��߱� �����Դϴ�.
- (0, 0)����(1, 1)�� �̵��� �� �ֽ��ϴ�.x��ǥ  y��ǥ ��� 2�̸� �̵��߱� ���� �Դϴ�.
- �̵��� �Է��� �޴°� �ƴϰ� 10ȸ ��� �������� �����Դϴ�.
- �Ź� �̵��� ���� ��ǥ�� ����� �� �־�� �մϴ�.
- �α� ����� UE_LOG�� Ȱ���մϴ�.
- step �Լ��� x��ǥ y��ǥ ���� �̵��� �Ÿ� �Դϴ�.
- ������ ���� ��ǥ��(x1, y1)�̶�� ���� ��ǥ��(x1 + step �Լ��� ���ϰ�, y1 + step�Լ��� ���� ��) �Դϴ�.
- step�Լ��� 0Ȥ�� 1�� �������� ��ȯ �մϴ�.
- move�Լ���(0, 0)���� 10ȸ �����̸鼭 ��ǥ�� ����մϴ�.�̵��� step �Լ��� Ȱ�� �˴ϴ�.

�̸� �����Ѵٸ� �Ʒ��� ���� Ŭ������ �� �� �Դϴ�.(�� �����Ͻ� �ʿ�� ���� ���� �ϼ���)*/

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FVector2D Step(FVector2D Position)
{
    int32 RandomValueX = FMath::RandRange(0, 1);
    int32 RandomValueY = FMath::RandRange(0, 1);

    return Position + FVector2D(RandomValueX, RandomValueY);
}

void Move()
{
    // FVector2D �迭 ����
    TArray<FVector2D> VectorArray;

    FVector2D Position(0, 0);

    // ������ �߰�
    for (int32 i = 0; i < 10; i++)
    {
        Position = Step(Position); // ���� ��ġ�� ���� ���� ��� ������
        VectorArray.Add(Position); // ������ ���͸� �迭�� �߰�
    }

    // ������ ���
    for (int32 i = 0; i < VectorArray.Num(); i++)
    {
        const FVector2D& Vec = VectorArray[i];
        UE_LOG(LogTemp, Warning, TEXT("Vector %d: X = %f, Y = %f"), i, Vec.X, Vec.Y);
    }
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
    Move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

