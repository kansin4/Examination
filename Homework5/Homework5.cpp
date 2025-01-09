// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "CoreMinimal.h"
#include <iostream>
using namespace std;

/*
시작점(0, 0) 있는 게임 캐릭터가 랜덤하게 10회 이동 합니다.각 스텝에서 거쳐간 좌표를 모두 출력하는게 목적입니다.

세부 요구사항은 아래와 같습니다.

- 시작점은(0, 0)이고 한번 이동시 x좌표와 y좌표 모두 2이상 이동할 수 없습니다.예를 들면 아래와 같습니다.
- (0, 0) 에서(1, 2)은 이동할수 없습니다.y좌표가 2이상 이동했기 때문입니다.
- (0, 0)에서(1, 1)은 이동할 수 있습니다.x좌표  y좌표 모두 2미만 이동했기 때문 입니다.
- 이동은 입력을 받는게 아니고 10회 모두 랜덤으로 움직입니다.
- 매번 이동시 현재 좌표를 출력할 수 있어야 합니다.
- 로그 출력은 UE_LOG를 활용합니다.
- step 함수는 x좌표 y좌표 각각 이동할 거리 입니다.
- 예를들어서 현재 좌표가(x1, y1)이라면 다음 좌표는(x1 + step 함수의 리턴값, y1 + step함수의 리턴 값) 입니다.
- step함수는 0혹은 1을 랜덤으로 반환 합니다.
- move함수는(0, 0)부터 10회 움직이면서 좌표를 출력합니다.이동시 step 함수가 활용 됩니다.

이를 구현한다면 아래와 같은 클래스가 될 것 입니다.(꼭 따라하실 필요는 없고 참고만 하세요)*/

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
    // FVector2D 배열 생성
    TArray<FVector2D> VectorArray;

    FVector2D Position(0, 0);

    // 데이터 추가
    for (int32 i = 0; i < 10; i++)
    {
        Position = Step(Position); // 이전 위치에 랜덤 값이 계속 누적됨
        VectorArray.Add(Position); // 누적된 벡터를 배열에 추가
    }

    // 데이터 출력
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

