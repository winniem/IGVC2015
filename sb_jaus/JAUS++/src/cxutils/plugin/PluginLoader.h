////////////////////////////////////////////////////////////////////////////////////
///
///  \file PluginLoader.h
///  \brief Class for loading plug-in libraries.
///
///  <br>Author(s): Daniel Barber
///  <br>Created: 25 July 2011
///  <br>Copyright (c) 2011
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: dbarber@ist.ucf.edu
///  <br>Web:  http://active.ist.ucf.edu
///
///  Redistribution and use in source and binary forms, with or without
///  modification, are permitted provided that the following conditions are met:
///      * Redistributions of source code must retain the above copyright
///        notice, this list of conditions and the following disclaimer.
///      * Redistributions in binary form must reproduce the above copyright
///        notice, this list of conditions and the following disclaimer in the
///        documentation and/or other materials provided with the distribution.
///      * Neither the name of the ACTIVE LAB, IST, UCF, nor the
///        names of its contributors may be used to endorse or promote products
///        derived from this software without specific prior written permission.
///
///  THIS SOFTWARE IS PROVIDED BY THE ACTIVE LAB''AS IS'' AND ANY
///  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
///  DISCLAIMED. IN NO EVENT SHALL UCF BE LIABLE FOR ANY
///  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
///  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
///  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
///  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
///  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
///  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
////////////////////////////////////////////////////////////////////////////////////
#ifndef __CXUTILS_PLUGIN_LOADER__H
#define __CXUTILS_PLUGIN_LOADER__H

#include "cxutils/plugin/Plugin.h"
#include <map>

namespace CxUtils
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class PluginLoader
    ///   \brief Class for loading a plugin library.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class CX_UTILS_DLL PluginLoader
    {
    public:
        typedef void* (*InitFunction)(void);
        PluginLoader();
        virtual ~PluginLoader();
        bool OpenModule(const std::string& filename,
                        const std::string& moduleName = "");
        void CloseModule(const std::string& moduleName = "");
        Plugin* CreatePlugin(const std::string& moduleName,
                             const std::string& pluginCreateFuncName) const;
        void* LoadPluginFunction(const std::string& moduleName,
                                 const std::string& pluginFuncName) const;
    protected:
        std::map<std::string, void*> mPluginLibraries; ///< Loaded libraries
    };
}

#endif
/*  End of File */
