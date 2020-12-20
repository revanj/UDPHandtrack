// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Core/Public/HAL/Runnable.h"
#include "Core/Public/HAL/Platform.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include<winsock2.h>
#include <thread>
#include <stdlib.h>
#include <atomic>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#define BUFLEN 512	//Max length of buffer
#define PORT 9000	//The port on which to listen for incoming data

#include "FPSCharacter.generated.h"

UCLASS()
class HANDTRACKTESTUNREAL_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();
	std::atomic<float> EllipseWidth, EllipseHeight, EllipseCenterX, EllipseCenterY, EllipseAngle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles input for moving forward and backward.
	UFUNCTION()
	void MoveForward(float Value);

	// Handles input for moving right and left.
	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void Turn(float Value);

	UFUNCTION()
	void LookUp(float Value);
	
	UFUNCTION()
	void UDPRun() {
		check(GEngine != nullptr);
		// Display a debug message for five seconds. 
		// The -1 "Key" value argument prevents the message from being updated or refreshed.
		
		SOCKET s;
		struct sockaddr_in server, si_other;
		int slen, recv_len;
		char buf[BUFLEN];
		WSADATA wsa;

		slen = sizeof(si_other);

		//Initialise winsock
		if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		{
			printf("Failed. Error Code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		printf("Initialised.\n");

		//Create a socket
		if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
		{
			printf("Could not create socket : %d", WSAGetLastError());
		}
		printf("Socket created.\n");

		//Prepare the sockaddr_in structure
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = INADDR_ANY;
		server.sin_port = htons(PORT);

		//Bind
		if (bind(s, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
		{
			printf("Bind failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		//keep listening for data
		while (1)
		{
			fflush(stdout);

			//clear the buffer by filling null, it might have previously received data
			memset(buf, '\0', BUFLEN);

			//try to receive some data, this is a blocking call
			if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*)&si_other, &slen)) == SOCKET_ERROR)
			{
				printf("recvfrom() failed with error code : %d", WSAGetLastError());
			}
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString(buf));
			//print details of the client/peer and the data received
			//myfile << "Received packet from" << inet_ntoa(si_other.sin_addr) << ntohs(si_other.sin_port) << std::endl;
		}

		closesocket(s);
		WSACleanup();

	}
};