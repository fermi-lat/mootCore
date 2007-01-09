// $Header: /nfs/slac/g/glast/ground/cvs/mootCore/mootCore/MootQuery.h,v 1.1.1.1 2006/11/21 01:18:04 jrb Exp $
// Handles registering a single file into Parameters table.  
// Might also handle other parts of building a config; TBD.
#ifndef MOOT_MootQuery_h
#define MOOT_MootQuery_h

#include <string>
#include <vector>
#include "rdbModel/Tables/Column.h"
#include "mootCore/FileDescrip.h"

/** @file MootQuery.h
    @author J. Bogart
  
    Declare the class MootQuery which provides facilities to 
    register components of a configuration in the configuration tracking
    database MOOD.
*/
namespace rdbModel {
  class Rdb;
  class Connection;
}

typedef std::vector<std::string> VectorOfString;
namespace MOOT {
  class MoodConnection;

  class MootQuery   {
  public:
    /// Use connection if one is supplied; else get a new read connection
    MootQuery(MoodConnection* mood=0);

    ~MootQuery();

    /**
       Given a config key (unsigned), return associated list of fsw input
       keys (that is, primary keys from MOOT's FSW_inputs table)
       By default, only return list if the Config has status
       "CREATED".
     */
    bool getConfigInputs(unsigned configKey, 
                         std::vector<std::string>& inputKeys,
                         bool goodStatus = true);

    /**
       Given a config key (string), return associated list of fsw input
       keys (that is, primary keys from MOOT's FSW_inputs table)
       By default, only return list if the Config has status
       "CREATED".
     */
    bool getConfigInputs(const std::string& configKeyStr, 
                         std::vector<std::string>& inputKeys,
                         bool goodStatus = true);

    /**
       Given a config key, return associated list of fmx relative
       file paths.  Such a file path is what fmx upload expects
       as input.  Require Config to have good status.
     */
    bool getConfigFmxPaths(const std::string& configKey, 
                           std::vector<std::string>& paths);

    bool getConfigFswInfo(const std::string& configKey,
                          std::vector<FswInfo>& info, bool clear=true);

    bool getConfigFmxPaths(unsigned configKey, 
                           std::vector<std::string>& paths);

    bool getConfigFswInfo(unsigned configKey,
                          std::vector<FswInfo>& info, bool clear=true);
    /**
       look up by name; use most recent config with good status
     */
    bool getConfigFmxPathsByName(const std::string& configName, 
                                 std::vector<std::string>& paths);

    bool getConfigFswInfoByName(const std::string& configName,
                                std::vector<FswInfo>& info, bool clear=true);


    /**
       look up by alg name and step; use most recent config with good status
     */
    bool getConfigFmxPathsByAlg(const std::string& algName,
                                const std::string& algStep,
                                std::vector<std::string>& paths);

    bool getConfigFmxPathsByAlg(const std::string& algName,
                                unsigned algStep,
                                std::vector<std::string>& paths);

    bool getConfigFswInfoByAlg(const std::string& algName,
                               const std::string& algStep,
                                std::vector<FswInfo>& info, bool clear=true);


    bool getConfigFswInfoByAlg(const std::string& algName,
                               unsigned algStep,
                               std::vector<FswInfo>& info, bool clear=true);

    /**
       Given fmx log. key for latc master file, return list of
       pairs. Each element in pair consists of file path in
       MOOT archive and string specifying latc component
       ..what about tower #?  Might need that if LATC inputs
        are split along tower boundaries
    */
    bool getLatcSrc(const std::string& latcMasterKey,
                    std::vector<FileDescrip>& sources);

    bool getLatcSrc(unsigned latcMasterKey,
                    std::vector<FileDescrip>& sources);


    /**
       Return list of keys for all good Configs (by default) or all
       configs with specified status.  By convention, if status
       argument is supplied and is equal to empty string, all
       config keys will be returned.
     */
    unsigned listConfigKeys(std::vector<unsigned>& keys, 
                            const std::string& status="CREATED",
                            const std::string& instr="LAT");
                            

    /**

    */
    unsigned getLastConfigKeyByName(const std::string& name, 
                                    const std::string& status="CREATED",
                                    const std::string& instr="LAT");

    unsigned getLastConfigKeyByAlg(const std::string& alg, unsigned step=1,
                                   const std::string& status="CREATED",
                                   const std::string& instr="LAT");


    unsigned getConfigKeysByName(std::vector<unsigned>& keys, 
                                 const std::string& name, 
                                 const std::string& status="CREATED",
                                 const std::string& instr="LAT");

    /**
       return list of all keys of configs with algorithm name algname,
       alg_step = step.  Empty string for @status or @instr argument
       means any value is acceptable.  Similarly, @step=0 means
       Config can have any value for step.
     */
    unsigned getConfigKeysByAlg(std::vector<unsigned>& keys, 
                                const std::string& algname,
                                unsigned step=1,
                                const std::string& status="CREATED",
                                const std::string& instr="LAT");

    /**
       Store a list of structures in @info argument concerning configs 
       which satisfy cuts on status, instrument and mode.  They're sorted
       in ascending order by key.  Return value is count of Configs
       satisfying the cuts.
     */
    unsigned getConfigInfo(std::vector<ConfigInfo>& info,
                           const std::string& status="CREATED",
                           const std::string& instr="LAT",
                           const std::string& mode="");

    /**
       Translate  class key to corresponding string.
       Return empty string if there is no translation
    */
    std::string classStr(const std::string& table, unsigned key);

    /**
       Translate string to key.  Return -1 if there is no translation
     */
    int classKey(const std::string& table, const std::string& name);

    std::string fswClassString(unsigned key) {
      return classStr("FSW_class", key);
    }

    int fswClassKey(const std::string& name) {
      return classKey("FSW_class", name);
    }

    // Fill supplied argument with parameter class names. Return count
    unsigned getParameterClasses(std::vector<std::string>& names);

    /**
       Return keys of parameter entries used to build FSW inputs
       for this config
     */
    bool getConfigParmsUsed(unsigned configKey, 
                            std::vector<unsigned>& parameterKeys);


    /**
       Return keys of parameter entries supplied when config was
       created.
     */
    bool getConfigParmsRequest(unsigned configKey, 
                               std::vector<unsigned>& parameterKeys);

    

  private:
    rdbModel::Rdb* m_rdb;
    MoodConnection* m_mood;
    bool            m_ownConnection; // if true, will need to delete 
    std::string     m_archive;  // translation of MOOT_ARCHIVE env. var.
    bool            m_dbg;
  };
}

#endif
