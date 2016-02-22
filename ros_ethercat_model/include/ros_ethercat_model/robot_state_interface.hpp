/*
 * robot_state.hpp
 *
 *  Created on: 19 Feb 2016
 *      Author: Toni Oliver
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2016, Shadow Robot Company Ltd.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#ifndef ROS_ETHERCAT_MODEL_ROBOT_STATE_INTERFACE_HPP
#define ROS_ETHERCAT_MODEL_ROBOT_STATE_INTERFACE_HPP

#include <hardware_interface/internal/hardware_resource_manager.h>
#include "ros_ethercat_model/robot_state.hpp"


namespace ros_ethercat_model
{

/** A handle used to read the state of a single joint. */
class RobotStateHandle
{
public:
  RobotStateHandle() : name_(), state_(0) {}

  /**
   * \param name The name of the joint
   * \param state A pointer to the RobotState structure
   */
  RobotStateHandle(const std::string& name, RobotState* state)
    : name_(name), state_(state)
  {
    if (!state)
    {
      throw hardware_interface::HardwareInterfaceException("Cannot create handle '" + name + "'. RobtState data pointer is null.");
    }
  }

  std::string getName() const {return name_;}
  RobotState* getState() const {assert(state_); return state_;}

private:
  std::string name_;
  RobotState* state_;
};

/** \brief Hardware interface to support reading the state of an array of joints
 *
 * This \ref HardwareInterface supports reading the state of an array of named
 * joints, each of which has some position, velocity, and effort (force or
 * torque).
 *
 */
class RobotStateInterface : public hardware_interface::HardwareResourceManager<RobotStateHandle> {};

}

#endif
