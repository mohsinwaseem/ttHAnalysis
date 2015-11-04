void runTestEventYield(const std::string MulticrabDir = "", 
                    const std::string SampleName = "", 
                    const std::string text = "",
                    const int MaxEvents = -1)
{
  gSystem->CompileMacro("TestEventYield.C");
  const std::string absolutePath = "/home/athermw/Research/rootFiles";
  TestEventYield macro(absolutePath + "/" + MulticrabDir,SampleName, text, MaxEvents);
  macro.Loop();
}
