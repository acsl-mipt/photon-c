/* Type implementation */
#include "photon/identification/PhotonGtComponentNumberGuidPair.h"


PhotonResult PhotonGtComponentNumberGuidPair_Serialize(PhotonGtComponentNumberGuidPair self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < /* component_number_guid_pair{ */sizeof(PhotonGtBer)/* }component_number_guid_pair */)
    return PhotonResult_NotEnoughSpace;
  PhotonBer_Serialize(self.number, writer);
  PhotonBer_Serialize(self.guid, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtComponentNumberGuidPair_Deserialize(PhotonGtComponentNumberGuidPair* self, PhotonReader* reader) {
  PhotonBer_Deserialize(&self->number, reader);
  PhotonBer_Deserialize((PhotonGtBer*) &self->guid, reader);
  return PhotonResult_Ok;
}