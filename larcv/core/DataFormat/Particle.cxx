#ifndef __PARTICLE_CXX__
#define __PARTICLE_CXX__

#include "Particle.h"
#include <set>
#include <sstream>
namespace larcv {

  std::string Particle::dump() const
  {
    std::stringstream ss;
    std::stringstream buf;
    ss  << "      \033[95m" << "Particle " << " (PdgCode,TrackID) = (" << PdgCode() << "," << TrackID() << ")\033[00m "
	<< "... with Parent (" << ParentPdgCode() << "," << ParentTrackID() << ")" << std::endl;
    buf << "      ";

    ss << buf.str() << "Vertex   (x, y, z, t) = (" << X() << "," << Y() << "," << Z() << "," << T() << ")" << std::endl
       << buf.str() << "Momentum (px, py, pz) = (" << Px() << "," << Py() << "," << Pz() << ")" << std::endl
       << buf.str() << "Inittial Energy  = " << EnergyInit() << std::endl
       << buf.str() << "Deposit  Energy  = " << EnergyDeposit() << std::endl
       << buf.str() << "Creation Process = " << CreationProcess() << std::endl;

    ss << buf.str() << "BBox3D: " << _bb3d.dump();
    buf << "    ";
    for(size_t i=0; i<_bb2d_v.size(); ++i)
      ss << buf.str() << "Plane " << i << " BBox2D: " << _bb2d_v[i].dump();
      
    return ss.str();
  }
  
}

#endif