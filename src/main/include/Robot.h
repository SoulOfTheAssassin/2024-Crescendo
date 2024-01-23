// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project

#pragma once

#include <frc/Encoder.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/event/EventLoop.h>
#include <frc/simulation/DifferentialDrivetrainSim.h>
#include <frc/simulation/EncoderSim.h>
#include <frc/smartdashboard/Field2d.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/DoubleTopic.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

#include <string>

#include "AlphaArm.h"
#include "Climber.h"
#include "Intake.h"
#include "Mag.h"
#include "Behaviours/AlphaArmBehaviour.h"
#include "Behaviours/ClimberBehaviour.h"
#include "Behaviours/IntakeBehaviour.h"
#include "Behaviours/MagBehaviour.h"
#include "RobotMap.h"
#include "Wombat.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  behaviour::BehaviourScheduler* sched;

  RobotMap robotmap;

  frc::EventLoop loop;
  frc::SendableChooser<std::string> m_chooser;
  frc::Field2d m_field;
  frc::Timer simulation_timer;
  frc::SendableChooser<std::string> m_path_chooser;

  wom::SwerveDrive* _swerveDrive;

  AlphaArm* alphaArm;
  Mag* mag;
  Climber* climber;
  Intake* intake;
};
