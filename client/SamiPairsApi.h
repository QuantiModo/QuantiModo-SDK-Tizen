#ifndef SamiPairsApi_H_
#define SamiPairsApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

#include "SamiPairs.h"
using Tizen::Base::String;
using Tizen::Base::Integer;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiPairsApi {
public:
  SamiPairsApi();
  virtual ~SamiPairsApi();

  IList* 
  v1PairsCsvGetWithCompletion(String* cause, String* effect, String* accessToken, String* causeSource, String* causeUnit, String* delay, String* duration, String* effectSource, String* effectUnit, String* endTime, String* startTime, Integer* limit, Integer* offset, Integer* sort, void (* handler)(IList*, SamiError*));
  IList* 
  v1PairsGetWithCompletion(String* cause, String* effect, String* accessToken, String* causeSource, String* causeUnit, String* delay, String* duration, String* effectSource, String* effectUnit, String* endTime, String* startTime, Integer* limit, Integer* offset, Integer* sort, void (* handler)(IList*, SamiError*));
  static String getBasePath() {
    return L"https://app.quantimo.do/api";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiPairsApi_H_ */
